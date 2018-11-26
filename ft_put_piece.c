/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:41:33 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/23 21:42:03 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_piece(char *piece, char **square, int j, int k)
{
	int	i;

	i = 0;
	while (!ft_isalpha(*piece))
	{
		piece++;
		i++;
	}
	i = k - (i % 5);
	while (*piece)
	{
		if (ft_isalpha(*piece) && square[j][k] == '.')
			square[j][k] = *piece;
		k++;
		piece++;
		if (*piece == '\n')
		{
			j++;
			k = i;
			piece++;
		}
	}
	*(piece + 2) = 1;
}
