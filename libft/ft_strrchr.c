/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:37:01 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/05 15:19:23 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (c == '\0')
		i++;
	while (i--)
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
	}
	return (0);
}
