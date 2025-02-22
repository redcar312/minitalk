/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:26:03 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 14:40:34 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t size)
{
	char	*copy;
	size_t	i;

	copy = str;
	i = 0;
	while (i < size)
	{
		copy[i] = c;
		i++;
	}
	str = copy;
	return (str);
}
