/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:02:16 by mhurtamo          #+#    #+#             */
/*   Updated: 2024/11/11 13:13:48 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	if (!current->next)
	{
		del(current->content);
		free(current);
	}
	else
	{
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
			del(prev->content);
			free(prev);
		}
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
