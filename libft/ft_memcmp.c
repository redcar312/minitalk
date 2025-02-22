/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:19:33 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 14:37:21 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;
	int				i;

	i = 0;
	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (n--)
	{
		if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		i++;
	}
	return (0);
}
