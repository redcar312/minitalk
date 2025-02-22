/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:58:53 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 14:54:28 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	is_present(char const *str, char const *substr, int chars_left)
{
	int	i;

	i = 0;
	while (substr[i])
	{
		if (substr[i] != str[i] || i > chars_left - 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(char const *str, char const *substr, size_t n)
{
	char	*s;
	size_t	i;
	int		j;

	s = (char *)str;
	i = 0;
	if (substr[0] == '\0')
		return (s);
	while (i < n && str[i])
	{
		if (str[i] == substr[0])
		{
			j = n - i;
			if (is_present(&str[i], substr, j))
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
