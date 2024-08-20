/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 01:31:09 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 01:59:54 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
		if (search(my_env, cmd[i]))
			delete(my_env, cmd[i]);
		else if (search(my_exp, cmd[i]))
			delete(my_exp, cmd[i]);
		i++;
	}
}
