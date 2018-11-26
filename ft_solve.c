/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:59:21 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/25 21:41:51 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tab_len(char **tab)
{
	int	i;

	i = 0;
	while (ft_strcmp(tab[i], "end"))
		i++;
	return (i);
}

int		check_pieces(char **pieces, int l)
{
	int	k;

	k = 0;
	while (k < tab_len(pieces))
	{
		if (!(ft_strcmp(pieces[l], "end")))
			l = 0;
		if (pieces[l][22] == 0)
			return (l);
		l++;
		k++;
	}
	return (-1);
}

int		fillit(char **pieces, char **square, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (l == -1)
		return (1);
	while (ft_strcmp(square[i], "end"))
	{
		while (square[i][j] != '\n')
		{
			if (square[i][j] == '.' && ft_piece_fit(pieces[l], square, i, j))
			{
				ft_put_piece(pieces[l], square, i, j);
				if (fillit(pieces, square, check_pieces(pieces, l + 1)) == 1)
					return (1);
				pieces[l][22] = 0;
				reset_piece(pieces[l], square);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	**solve(char **pieces, int size)
{
	char	**square;

	square = ft_create_map(size);
	if (fillit(pieces, square, 0))
		return (square);
	else
	{
		ft_freetab((void ***)&square);
		return (solve(pieces, size + 1));
	}
}
