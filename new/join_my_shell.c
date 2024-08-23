/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_my_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:41:40 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:50:01 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	join = ft_malloc(i + j + 2, 0);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	join[j++] = ' ';
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*join_my_command(t_shell shell)
{
	t_list	*flags;
	char	*my_command;
	char	*tmp;

	if (!shell.flags)
		return (shell.cmd);
	flags = shell.flags;
	my_command = my_join(shell.cmd, flags->content);
	flags = flags->next;
	while (flags)
	{
		tmp = my_command;
		my_command = my_join(my_command, flags->content);
		free(tmp);
		flags = flags->next;
	}
	return (my_command);
}

void	join_my_shell(t_minishell *minishell, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		minishell->shell[i].full_commnad = join_my_command(minishell->shell[i]);
		i++;
	}
}
