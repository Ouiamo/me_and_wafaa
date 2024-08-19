/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:34:07 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/18 15:29:46 by wzahir           ###   ########.fr       */
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
	// if (equal_sign(str) == 0)
	// 	return (EXIT_FAILURE);
	while (str[i] && str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	exist_value(t_env *my_env, char *str)
{
	while (my_env->export)
	{
		if (ft_strncmp(my_env->export, str, equal_sign(my_env->export)) == 0)
		{
			free(my_env->export);
			my_env->export = ft_strdup(str);
			return (1);
		}
		my_env = my_env->next;
	}
	return (0);
}

int	ft_export(t_env *my_exp, char ** cmd)
{
	//char	**tmp;
	int		i;
	t_env *node;

	i = 1;
	if (!cmd[1])
		print_sorted_exp(my_exp);
	else
	{
		while (cmd[i])
		{
			if (!cmd[i][0] || cmd[i][0] == ' ' || cmd[i][0] == '\t')
				return (export_error(cmd[i]));
			if (!check_arg(cmd[i]))
			{
				if (equal_sign(cmd[i]) == 0 )
				{
					node = ft_lstnew(cmd[i], NULL);
					ft_lstadd_back(&my_exp, node) ;
					//  while(my_exp)
    				// {
   					//     printf("%s\n  ", my_exp->export);
   				    //  	my_exp=my_exp->next;
    				// }
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}