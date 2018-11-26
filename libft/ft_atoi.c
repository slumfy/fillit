/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:13:28 by varuiz            #+#    #+#             */
/*   Updated: 2018/11/09 17:24:35 by varuiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			i;
	int			check_sign;
	int			neg;
	long int	nbr;

	i = 0;
	nbr = 0;
	neg = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		check_sign = (nbr < 0) ? -1 : 1;
		nbr = nbr * 10 + str[i] - '0';
		if ((nbr < 0 && check_sign == 1) || (nbr > 0 && check_sign == -1))
			return (neg == -1 ? 0 : -1);
		i++;
	}
	return (neg * nbr);
}
