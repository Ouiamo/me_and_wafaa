/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:33:36 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:48:13 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_user_text(char *limiter)
{
	static char	*line;
	char		*text;
	int			i;

	i = 0;
	text = NULL;
	line = readline(">");
	while (line && ft_strcmp(line, limiter))
	{
		if (i++ == 0)
			text = ft_other_join(line, "\n");
		else
		{
			text = ft_other_join(text, line);
			text = ft_other_join(text, "\n");
			free(line);
		}
		line = readline(">");
	}
	if (line)
		free(line);
	return (text);
}

char	*my_heredoc(char *limiter)
{
	char	*text;
	int		fd;

	text = get_user_text(limiter);
	// expand_varibles;
	fd = open("chose name later", O_CREAT | O_WRONLY | O_TRUNC);
	write(fd, text, ft_strlen(text));
	free(text);
	close(fd);
	return ("chose name later");
}

t_shell	add_in_file(char *redir, t_shell shell, char *name)
{
	t_list	*new_file;
	t_list	*list_file;

	new_file = ft_malloc(sizeof(t_list), 0);
	list_file = shell.infiles;
	new_file = ft_malloc(sizeof(t_list), 0);
	list_file = shell.infiles;
	if (redir[1])
		new_file->herdoc = my_heredoc(name);
	else
	{
		new_file->fd = open(name, O_RDONLY);
		if (new_file->fd < 0)
			printf("minishell: %s: No such file or directory\n", name);
	}
	new_file->next = list_file;
	shell.infiles = new_file;
	return (shell);
}

t_shell	add_out_file(char *redir, t_shell shell, char *name)
{
	t_list	*new_file;
	t_list	*list_file;

	new_file = ft_malloc(sizeof(t_list), 0);
	list_file = shell.outfiles;
	if (redir[1])
		new_file->fd = open(name, O_CREAT | O_APPEND | O_RDONLY, 0644);
	else
		new_file->fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (new_file->fd < 0)
		printf("ERROR : we can not open %s for personal resones :)\n", name);
	new_file->next = list_file;
	shell.outfiles = new_file;
	return (shell);
}

t_shell	add_redir(char **arr, t_shell shell)
{
	char	*my_redir;

	my_redir = *arr;
	arr++;
	if (my_redir[0] == '>')
		shell = add_out_file(my_redir, shell, *arr);
	if (my_redir[0] == '<')
		shell = add_in_file(my_redir, shell, *arr);
	return (shell);
}
