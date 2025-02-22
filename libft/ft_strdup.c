/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:04:43 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/05 15:08:24 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *str)
{
	char	*cstr;
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	cstr = (char *)malloc((i + 1) * sizeof(char));
	if (cstr == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		cstr[i] = str[i];
		i++;
	}
	cstr[i] = '\0';
	return (cstr);
}
