/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:27:53 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/05 14:24:48 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	c;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
	write(fd, "\n", 1);
}
