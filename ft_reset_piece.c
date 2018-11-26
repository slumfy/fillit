/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:33:42 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/22 04:25:07 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_piece(char *piece, char **square)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (!ft_isalpha(*piece))
		++piece;
	while (k < 4)
	{
		while (square[i][j] != '\n')
		{
			if (square[i][j] == *piece)
			{
				square[i][j] = '.';
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
