/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:16:03 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/22 04:27:27 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_piece_letter(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strcmp(tab[i], "end"))
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = 'A' + i;
			j++;
		}
		j = 0;
		i++;
	}
}
