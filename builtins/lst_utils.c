/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:51:04 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/19 22:01:35 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew(char *key, char *value, char *envp)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node -> key = key;
    node -> value = value;
	node -> envp = envp;
	node -> next = NULL;
	return (node);
}

// void	ft_lstadd_front(t_env **lst, t_env *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new -> next = *lst;
// 	*lst = new;
// }

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*node;

	if (!lst || !new)
		return ;
	node = *lst;
	if (*lst)
	{
		while (node -> next != NULL)
			node = node -> next;
		node -> next = new;
	}
	else
		*lst = new;
}


// int	ft_lstsize(t_env *lst)
// {
// 	int		k;
// 	t_env	*node;

// 	node = lst;
// 	k = 0;
// 	while (node != NULL)
// 	{
// 		k++;
// 		node = node -> next;
// 	}
// 	return (k);
// }

// t_env	*ft_lstlast(t_env *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst -> next != NULL)
// 		lst = lst -> next;
// 	return (lst);
// }
