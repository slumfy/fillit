/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:17:59 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/23 21:40:46 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((tab = taballoc(size, size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		while (j < size + 1)
		{
			tab[i][j] = '.';
			if (j == size)
				tab[i][j] = '\n';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}
