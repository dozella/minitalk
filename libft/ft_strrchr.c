/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:12:59 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:13:02 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)s + ft_strlen(s);
	sym = (char)c;
	while (ptr >= s)
	{
		if (*ptr == sym)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
