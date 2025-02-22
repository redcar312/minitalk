/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:19:04 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/04 17:54:29 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	get_len(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*cstr;
	size_t				len;

	if (!s)
		return (0);
	len = get_len(s);
	cstr = (char *)malloc((len + 1) * sizeof(char));
	if (cstr == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		cstr[i] = f(i, s[i]);
		if (!cstr[i])
			return (0);
		i++;
	}
	cstr[i] = '\0';
	return (cstr);
}
