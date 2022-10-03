/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:09:20 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:19:04 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_tab_str(char ***strs, size_t max_size)
{
	size_t	i;

	i = 0;
	while (i < max_size)
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

static void	ft_process_split(char ***strs, const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (len == 0)
			break ;
		(*strs)[i] = ft_substr(s, 0, len);
		if ((*strs)[i] == NULL)
		{
			ft_free_tab_str(strs, i);
			break ;
		}
		i++;
		s += len;
	}
}

static size_t	ft_get_word_count(const char *s, char c)
{
	size_t	w_c;

	w_c = (*s != c && *s != '\0');
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s == '\0')
				break ;
			w_c++;
		}
		s++;
	}
	return (w_c);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	w_c;

	strs = NULL;
	if (s != NULL)
	{
		w_c = ft_get_word_count((const char *)s, c);
		strs = (char **)malloc(sizeof(char *) * (w_c + 1));
		if (strs != NULL)
		{
			strs[w_c] = NULL;
			ft_process_split(&strs, s, c);
		}
	}
	return (strs);
}
