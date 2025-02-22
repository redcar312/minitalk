/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:06:56 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 14:55:28 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	get_len(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

static size_t	get_dlen(char *dest, size_t max)
{
	size_t	l;

	l = 0;
	if (!dest || max == 0)
		return (l);
	while (dest[l] && l < max)
	{
		l++;
	}
	return (l);
}

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	total;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = get_len(src);
	dest_len = get_dlen(dest, size);
	total = src_len + dest_len;
	if (dest_len == size)
		return (src_len + size);
	if (size < 1)
		return (size + src_len);
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (total);
}
