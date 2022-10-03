/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:06:00 by dozella           #+#    #+#             */
/*   Updated: 2021/11/15 20:55:08 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_fill_str(long n, char *str, size_t size)
{
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		size--;
		str[size] = n % 10 + 48;
		n = n / 10;
	}
}

static size_t	ft_get_size_of_nbr(long n)
{
	size_t	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_get_size_of_nbr((long)n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
		ft_fill_str((long)n, str, size);
	return (str);
}
