/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_my_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:31:05 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:49:17 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	creat_my_shell(t_minishell *minishell, char **arr)
{
	int	i;

	i = 0;
	while (*arr)
	{
		if (**arr == '|' || **arr == '&')
		{
			minishell->shell[i] = add_pipetype(*arr, minishell->shell[i]);
			i++;
		}
		else if (**arr == '(' || **arr == ')')
			minishell->shell[i] = add_prnt(**arr, minishell->shell[i]);
		else if (**arr == '<' || **arr == '>')
			minishell->shell[i] = add_redir(arr, minishell->shell[i]);
		else
			minishell->shell[i] = add_cmd(&arr, minishell->shell[i]);
		arr++;
	}
}
