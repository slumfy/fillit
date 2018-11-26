/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:37:54 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/25 21:46:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid(char *str, int j, int i, int x)
{
	if (str[i + 1] == '#' || str[i + 5] == '#' || ((str[i + 4] == '#' ||
					str[i + 3] == '#') && str[i - 1] == '#'))
		j++;
	else if (j == 3 * (x + 1) + x && (str[i - 1] == '#' ||
				str[i - 5] == '#'))
		j++;
	return (j);
}

int		valid_piece(char *str, int n)
{
	static int tab[5] = {0};

	while (str[tab[0]] == '.' || str[tab[0]] == '#' || str[tab[0]] == '\n')
	{
		if (str[tab[0]] == '#')
		{
			tab[3]++;
			tab[1] = valid(str, tab[1], tab[0], tab[2]);
		}
		if (str[tab[0]] == '\n')
		{
			tab[4]++;
			if (tab[4] > 5)
				return (0);
			if (str[tab[0] - 1] == '\n')
			{
				tab[4] = 0;
				tab[2]++;
			}
		}
		tab[0]++;
	}
	return (tab[1] != (4 * n) || tab[3] != (4 * n) ||
			tab[0] != (20 * n + 1 * (n - 1)) ? 0 : 1);
}
