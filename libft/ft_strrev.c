/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:00:56 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/10 15:06:32 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		i;
	char	c;

	count = 0;
	while (str[count] != '\0')
		count++;
	count = count - 1;
	i = 0;
	while (i < ((count + 1) / 2))
	{
		c = str[i];
		str[i] = str[count - i];
		str[count - i] = c;
		i++;
	}
	return (str);
}
