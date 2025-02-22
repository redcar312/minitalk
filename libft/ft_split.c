/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:26:33 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/06 15:39:49 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	count_rows(char const *str, char c)
{
	int	i;
	int	rows;

	rows = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c)
			|| (str[i] != c && str[i + 1] == c))
		{
			rows++;
		}
		i++;
	}
	if (!rows)
		rows++;
	return (rows);
}

static void	free_arrs(char **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*make_str(char const *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
	}
	s = (char *)malloc((i + 1) * sizeof(char));
	if (s == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void	assemble_arr(char **arr, char const *str, char c)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			arr[rows] = make_str(&str[i], c);
			if (arr[rows] == NULL)
			{
				if (!rows)
					rows++;
				free_arrs(arr, rows);
			}
			rows++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	arr[rows] = NULL;
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		rows;

	if (!str)
		return (0);
	rows = count_rows(str, c);
	arr = (char **)malloc((rows + 1) * sizeof(char *));
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	assemble_arr(arr, str, c);
	return (arr);
}
