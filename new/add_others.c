/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:39:00 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:47:46 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	add_pipetype(char *arr, t_shell shell)
{
	if (arr[0] == '|' && arr[1])
		shell.pipe_type = 2;
	else if (arr[0] == '|')
		shell.pipe_type = 1;
	else
		shell.pipe_type = 3;
	return (shell);
}

t_shell	add_prnt(char c, t_shell shell)
{
	if (c == '(')
		shell.prnt++;
	else if (c == ')')
		shell.prnt--;
	return (shell);
}

char	*remove_quotes(char *arr)
{
	int		i;
	char	quote;
	char	*new;
	int		j;

	quote = 0;
	i = -1;
	while (arr[++i])
		if (arr[i] == 39 || arr[i] == 34)
			quote = arr[i];
	if (quote)
		new = ft_malloc(i - 1, 0);
	else
		new = ft_malloc(i + 1, 0);
	i = 0;
	j = 0;
	while (arr[i])
	{
		if (arr[i] == 39 || arr[i] == 34)
			i++;
		else
			new[j++] = arr[i++];
	}
	new[j] = '\0';
	return (new);
}

t_list	*add_flags(char *arr, t_shell shell)
{
	t_list	*new_flag;
	t_list	*tmp;

	new_flag = ft_malloc(sizeof(t_list), 0);
	new_flag->content = remove_quotes(arr);
	new_flag->next = NULL;
	if (!shell.flags)
		return (new_flag);
	tmp = shell.flags;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_flag;
	return (shell.flags);
}

t_shell	add_cmd(char ***arr, t_shell shell)
{
	while (**arr)
	{
		if (***arr == '|' || ***arr == '&' || ***arr == '(' || ***arr == ')'
			|| ***arr == '<' || ***arr == '>')
			break ;
		if (!shell.cmd)
			shell.cmd = remove_quotes(**arr);
		else
			shell.flags = add_flags(**arr, shell);
		(*arr)++;
	}
	(*arr)--;
	return (shell);
}
