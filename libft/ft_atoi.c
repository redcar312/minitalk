/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:11:35 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 12:52:37 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	calc_sum(char *str, int is_neg)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (i > 0)
			sum *= 10;
		sum += (str[i] - 48);
		i++;
	}
	if (is_neg)
		return (sum * -1);
	return (sum);
}

int	ft_atoi(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (calc_sum((char *)&str[i + 1], 1));
		if (str[i] == '+')
			return (calc_sum((char *)&str[i + 1], 0));
		if (str[i] == '\v' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == 32)
			i++;
		else
			return (calc_sum((char *)&str[i], 0));
	}
	return (0);
}
