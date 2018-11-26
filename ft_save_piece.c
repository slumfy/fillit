/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:27:01 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/26 07:01:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(char *pieces)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (pieces[i])
	{
		if (pieces[i] == '\n')
			j++;
		i++;
	}
	j++;
	return (j / 5);
}

void	create_tab(char *pieces, char **tab)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	while (pieces[j])
	{
		tab[k][l] = pieces[j];
		j++;
		l++;
		if (l == 20)
		{
			tab[k][22] = 0;
			k++;
			l = 0;
			j++;
		}
	}
	tab[k] = "end";
}

char	**check_error(char *pieces)
{
	int		num_pieces;
	char	**tab;

	if ((num_pieces = count_pieces(pieces)) > 26)
		return (NULL);
	if (valid_piece(pieces, num_pieces) == 0)
		return (NULL);
	if ((tab = taballoc(num_pieces, 22)) == NULL)
		return (NULL);
	return (tab);
}

char	**save_pieces(int fd)
{
	char	*pieces;
	char	**tab;
	char	c;
	int		i;
	int		k;

	i = 0;
	pieces = ft_strnew(1000);
	if ((k = read(fd, &c, 1)) == -1)
		return (NULL);
	while (k)
	{
		pieces[i] = c;
		i++;
		if ((k = read(fd, &c, 1)) == -1)
			return (NULL);
		if (i > 999)
			return (NULL);
	}
	if ((tab = check_error(pieces)) == NULL)
		return (NULL);
	create_tab(pieces, tab);
	free(pieces);
	close(fd);
	return (tab);
}
