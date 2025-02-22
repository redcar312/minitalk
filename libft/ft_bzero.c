/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:48:30 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 12:48:29 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_bzero(void *buffer, size_t n)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = buffer;
	while (i < n)
	{
		copy[i] = '\0';
		i++;
	}
	buffer = copy;
}
