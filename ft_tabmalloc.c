/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:13:22 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/26 01:33:38 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**taballoc(int l, int c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char**)malloc(sizeof(tab) * (l + 1));
	while (i < l)
	{
		tab[i] = ft_strnew(c);
		i++;
	}
	tab[i] = "end";
	return (tab);
}
