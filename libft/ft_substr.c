/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:13:26 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:13:29 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	true_len;

	str = NULL;
	if (s != NULL)
	{
		true_len = ft_strlen(s);
		if (len > true_len)
			len = true_len;
		if (start > true_len)
			start = (unsigned int)true_len;
		if (start + len > true_len)
			len = true_len - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			ft_memmove(str, s + start, len);
			str[len] = '\0';
		}
	}
	return (str);
}
