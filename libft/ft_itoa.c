/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:18 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/05 16:10:55 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	get_len(int n)
{
	int	i;

	i = 1;
	if (n >= 0)
	{
		while (n >= 10)
		{
			i++;
			n = n / 10;
		}
	}
	if (n < 0)
	{
		i++;
		while (n <= -10)
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}

static void	assemble_str(char *str, int n, int len)
{
	str[len] = '\0';
	len--;
	if (n >= 0)
	{
		while (n >= 10)
		{
			str[len] = '0' + n % 10;
			len--;
			n = n / 10;
		}
		str[len] = '0' + n;
	}
	else
	{
		while (n <= -10)
		{
			str[len] = '0' - n % 10;
			len--;
			n = n / 10;
		}
		str[len] = '0' - n;
		len--;
		str[len] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		copy;	

	copy = n;
	len = get_len(copy);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	assemble_str(str, n, len);
	return (str);
}
