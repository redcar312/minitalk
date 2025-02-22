/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:23:25 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 15:39:07 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	get_len(char const *s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (l);
	while (s[l])
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	i = 0;
	s_len = get_len(s);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	while (i < len && start < s_len)
	{
		substr[i] = s[start++];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
