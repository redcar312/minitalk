/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:31:56 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/05 15:15:17 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*cstr;
	int		i;

	i = 0;
	cstr = (char *)str;
	while (n--)
	{
		if (cstr[i] == c)
		{
			return (&cstr[i]);
		}
		i++;
	}
	return (0);
}
