/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:31:09 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 12:59:03 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void delete(t_env **head, char *key)
{
    t_env *tmp = *head;
    t_env *prev = NULL;

    if (tmp  && ft_strcmp(tmp->key, key) == 0)
    {
        *head = tmp->next;
    	ft_lstdelone(tmp);     
        return;
    }
    while (tmp && ft_strcmp(tmp->key, key) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return;
    prev->next = tmp->next;
	ft_lstdelone(tmp);
}

int search(t_env *ptr, char *key)
{
    t_env *current;

    current = ptr;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_unset(t_env *my_env, t_env *my_exp, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (search(my_exp, cmd[i]))
			delete(&my_exp, cmd[i]);
		if (search(my_env, cmd[i]))
			delete(&my_env, cmd[i]);
		i++;
	}
}
