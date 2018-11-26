/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:21:28 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/26 06:37:44 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_piece_fit(char *piece, char **square, int j, int k)
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
		if (ft_isalpha(*piece) && k < 0)
			return (0);
		if (ft_isalpha(*piece) && square[j][k] != '.')
			return (0);
		k++;
		if (*piece == '\n')
		{
			j++;
			k = i;
		}
		piece++;
	}
	return (1);
}
