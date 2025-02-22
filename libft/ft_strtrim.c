/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:27:32 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/19 19:35:21 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_len(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_sep(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	end_index;
	size_t	start_index;
	size_t	i;

	if (!s1 || !set)
		return (0);
	len = get_len(s1);
	i = 0;
	end_index = len;
	start_index = 0;
	while (s1[start_index] && is_sep(s1[start_index], set))
		start_index++;
	while (end_index > start_index && is_sep(s1[end_index - 1], set))
		end_index--;
	trimmed = (char *)malloc(((end_index - start_index) + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	while (start_index < end_index)
		trimmed[i++] = s1[start_index++];
	trimmed[i] = '\0';
	return (trimmed);

}

int	main()
{
	char *result;

	printf("I am testing -----> strtrim:\n");

	result = ft_strtrim("   he llo   ", " ");
	if (strcmp(result, "he llo") == 0)
		printf("Test1 for '   he llo   ' with ' ' is: ✅\n");
	else
		printf("Test1 for '   he llo   ' with ' ' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("--abc--def--", "-");
	if (strcmp(result, "abc--def") == 0)
		printf("Test2 for '--abc--def--' with '-' is: ✅\n");
	else
		printf("Test2 for '--abc--def--' with '-' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("", " ");
	if (strcmp(result, "") == 0)
		printf("Test3 for '' string with ' ' is: ✅\n");
	else
		printf("Test3 for '' string with ' ' is: 💀 (Got: \"%s\")\n", result);
	free(result);

	result = ft_strtrim("test", "");
	if (strcmp(result, "test") == 0)
		printf("Test4 for 'test' with '' set is: ✅\n");
	else
		printf("Test4 for 'test' with '' set is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("------", "-");
	if (strcmp(result, "") == 0)
		printf("Test5 for '------' with '-' is: ✅\n");
	else
		printf("Test5 for '------' with '-' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("hello", NULL);
	if (result == NULL)
		printf("Test6 for 'hello' with NULL set is: ✅\n");
	else
		printf("Test6 for 'hello' with NULL set is: 💀 (Got: \"%s\")\n", result);
	free(result);

	result = ft_strtrim(NULL, "x");
	if (result == NULL)
		printf("Test7 for NULL input string is: ✅\n\n");
	else
		printf("Test7 for NULL input string is: 💀 (Got: '%s')\n\n", result);
	free(result);
}
