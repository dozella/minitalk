/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:13:12 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:13:15 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	beg;
	ssize_t	end;
	size_t	len_s1;

	str = NULL;
	if (set == NULL && s1 != NULL)
		str = ft_strdup(s1);
	else if (s1 != NULL)
	{
		beg = 0;
		len_s1 = ft_strlen(s1);
		end = (ssize_t)len_s1;
		if (len_s1 > 0)
			end--;
		while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
			beg++;
		while (end >= 0 && ft_strchr(set, s1[end]) != NULL)
			end--;
		str = ft_substr(s1, (unsigned int)beg, ((size_t)(end) - beg + 1));
	}
	return (str);
}
