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

#include "minitalk.h"
int	f_isdigit(unsigned int c)
{
	if(c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}
int f_isxdigit(unsigned int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	return (0);
}

static int hexval(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

static long f_atol(const char *num) {
    long value = 0;
    int neg = 0;
    if (num[0] == '0' && num[1] == 'x') {

        num += 2;
        while (*num && f_isxdigit(*num))
            value = value * 16 + hexval(*num++);
    } else {
        if (num[0] == '-') {
            neg = 1;
            num++;
        }
        while (*num && f_isdigit(*num))
            value = value * 10 + *num++  - '0';
    }
    if (neg)
        value = -value;
    return value;
}

int	f_atoi(const char *str)
{
	return(f_atol(str));
}
