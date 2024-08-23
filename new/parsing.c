/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:12:27 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:50:18 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nbr_commands(char **arr)
{
	int	i;

	i = 1;
	while (*arr)
	{
		if (**arr == '|' || **arr == '&')
			i++;
		arr++;
	}
	return (i);
}

void	initial_my_shell(t_minishell *minishell, char **arr)
{
	int	i;

	i = nbr_commands(arr);
	minishell->shell = ft_malloc(sizeof(t_shell) * (i + 1), 0);
	while (i > -1)
	{
		minishell->shell[i].pipe_type = 0;
		minishell->shell[i].prnt = 0;
		minishell->shell[i].cmd = NULL;
		minishell->shell[i].flags = NULL;
		minishell->shell[i].full_commnad = NULL;
		i--;
	}
}

void	parsing(t_minishell *minishell, char **arr)
{
	initial_my_shell(minishell, arr);
	creat_my_shell(minishell, arr);
	join_my_shell(minishell, nbr_commands(arr));
}
