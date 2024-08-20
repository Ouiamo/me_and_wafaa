/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:34:07 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 00:49:10 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_identifier(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (str[0] == '=')
		return (export_error(str));
	while ((str[i] && str[i] != '='))
	{
		if (str[i] == '+' && str[i + 1] == '=')
			return (EXIT_SUCCESS);
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

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

int	ft_export(t_env *my_exp, char ** cmd, t_env *my_env)
{
	//char	**tmp;
	int		i;
	int		j;
	int 	k;
	t_env *node;
	char *key;
	char *value;

	i = 1;
	if (!cmd[i])
		print_sorted_exp(my_exp);
	else
	{
		while (cmd[i] && !check_arg(cmd[i]))
		{
		// if (!cmd[i][0] || cmd[i][0] == ' ' || cmd[i][0] == '\t')
		// 	return (export_error(cmd[i]));
			// j = ft_strchr(cmd[i], '=');
			// if (j)
			// {
			// 	key = ft_substr(cmd[i], 0, j);
			// 	value = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]));
			// 	if(exist_value(my_exp, key , value))
			// 	{
			// 		node = ft_lstnew(key, value, NULL);
			// 		ft_lstadd_back(&my_exp, node);
			// 	}
			// }
			// else
			// {
			// 	if(exist_value(my_exp, cmd[i] , NULL))
			// 	{
			// 		node = ft_lstnew(ft_strdup(cmd[i]), NULL , NULL);
			// 		ft_lstadd_back(&my_exp, node);
			// 	}
			// }
			j = ft_strchr(cmd[i], '=');
			k = ft_strchr(cmd[i], '+');
			if (j)
			{
				key = ft_substr(cmd[i], 0, j);
				value = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]));
				if(exist_value(my_exp, key , value))
				{
					node = ft_lstnew(key, value, NULL);
					ft_lstadd_back(&my_exp, node);
				}
			}
			else
			{
				if(exist_value(my_exp, cmd[i] , NULL))
				{
					node = ft_lstnew(ft_strdup(cmd[i]), NULL , NULL);
					ft_lstadd_back(&my_exp, node);
				}
			}
			env_from_exp(my_env, my_exp);	
			i++;
		}
	}
	return (EXIT_SUCCESS);
}


			// while(my_exp)
    			// {
   				// 	printf("key :%s  value : %s  env :%s\n", my_exp->key ,my_exp->value  , my_exp->envp);
   				//     my_exp = my_exp->next;
    			// }