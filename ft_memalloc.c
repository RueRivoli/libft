/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:43:53 by fgallois          #+#    #+#             */
/*   Updated: 2017/03/03 15:23:53 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *esp;

	esp = malloc(sizeof(char) * size);
	if (esp == NULL || size == 0)
		return (NULL);
	ft_bzero(esp, size);
	return (esp);
}
