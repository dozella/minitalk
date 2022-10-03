/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:02:40 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 00:02:43 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	size_t	total_size;

	tab = NULL;
	total_size = n * size;
	tab = malloc(total_size);
	if (tab != NULL)
		ft_bzero(tab, total_size);
	return (tab);
}
