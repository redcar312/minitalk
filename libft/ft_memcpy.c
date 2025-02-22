/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:19 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/07 13:50:28 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	cdest = dest;
	csrc = src;
	if (!dest && !src && n)
	{
		return (dest);
	}
	while (n--)
	{
		*cdest++ = *csrc++;
	}
	return (dest);
}
