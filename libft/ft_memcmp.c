/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:06:46 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:06:48 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
		{
			return (((const unsigned char *)s1)[i]
						- ((const unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
