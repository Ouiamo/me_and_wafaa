/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:34:07 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:30:59 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"


int	exist_value(t_env *my_exp, char *key, char *value)
{
	while (my_exp)
	{
		if (ft_strcmp(my_exp->key, key) == 0)
		{
			free(my_exp->value);
			free(my_exp->key);
			my_exp->key = ft_strdup(key);
			my_exp->value = ft_strdup(value);
			return (0);
		}
		my_exp = my_exp->next;
	}
	return (1);
}

int	add_value(t_env *my_exp, char *key, char *value)
{
	while (my_exp)
	{
		if (ft_strcmp(my_exp->key, key) == 0)
		{
			my_exp->value = ft_strjoin(my_exp->value, value);
			return (0);
		}
		my_exp = my_exp->next;
	}
	return (1);
}

void creat_node(t_env **my_exp, char *key, char *value, int n)
{
	t_env *node;
	
	if (n == 1)
	{
		node = ft_lstnew(key, value, NULL);
		ft_lstadd_back(my_exp, node);
	}
	else if (n == 2)
	{
		node = ft_lstnew(key, value , NULL);
		ft_lstadd_back(my_exp, node);
	}

}

void util_exp(char *cmd, t_env *my_exp)
{
	char *key;
	char *value;
	int		j;
	
	j = ft_strchr(cmd, '=');
	if (j && ft_strchr(cmd, '+'))
	{
		key = ft_substr(cmd, 0, ft_strchr(cmd, '+'));
		value = ft_substr(cmd, j + 1, ft_strlen(cmd));
		if(add_value(my_exp, key , value))
			creat_node(&my_exp, key, value, 1);
	}
	else if (j)
	{
		key = ft_substr(cmd, 0, j);
		value = ft_substr(cmd, j + 1, ft_strlen(cmd));
		if(exist_value(my_exp, key , value))
			creat_node(&my_exp, key, value, 1);
	}
	else
	{
		if(exist_value(my_exp, cmd , NULL))
			creat_node(&my_exp, ft_strdup(cmd), NULL, 2);
	}
}


int	ft_export(t_env *my_exp, char ** cmd, t_env *my_env)
{
	int		i;

	i = 1;
	if (!cmd[i])
		print_sorted_exp(my_exp);
	else
	{
		while (cmd[i] && !check_arg(cmd[i]))
		{
			// if (!cmd[i][0] || cmd[i][0] == ' ' || cmd[i][0] == '\t')
			// 	return (export_error(cmd[i]));
			util_exp(cmd[i], my_exp);
			env_from_exp(&my_env, my_exp);	
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
