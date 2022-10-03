/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:10:57 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:10:59 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (size <= len_dst)
		len_src = len_src + size;
	else
		len_src = len_src + len_dst;
	if (size > len_dst)
	{
		while (src[i] != '\0' && len_dst < size - 1)
		{
			dst[len_dst] = src[i];
			len_dst++;
			i++;
		}
		dst[len_dst] = '\0';
	}
	return (len_src);
}
