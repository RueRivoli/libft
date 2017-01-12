/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:54:48 by fgallois          #+#    #+#             */
/*   Updated: 2017/01/12 16:18:31 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int i;
	long j;
	long p;
	int signe;
	long ind;

	p = 0;
	signe = 1;
	i = 0;
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		i++;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]) == 1)
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		ind = (int)(str[i]) - 48;
		i++;
		j = 10 * p + ind;
		p = j;
	}
	p = signe * p;
	if (p > 2147483647)
		p = 0;
	if (p < -2147483648)
		p = -1;
	return ((int)p);
}

int main(void) {
	printf("%d\n", atoi("99999999999999999999999999"));
	printf("%d\n", ft_atoi("99999999999999999999999999"));
	printf("%d\n", atoi("-99999999999999999999999999"));
	printf("%d\n", ft_atoi("-99999999999999999999999999"));
	return(0);
}
