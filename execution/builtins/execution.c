/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:18:25 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:30:48 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

char	*check_cmd(t_minishell minishell, t_outils *p)
{
	int	fd;

	fd = open(minishell.shell->cmd, __O_DIRECTORY);
	if (!minishell.shell->cmd)
		return (NULL);
	else if (!ft_strncmp(minishell.shell->cmd, ".", 2) && !minishell.shell->cmd_args[1])
		ft_util_2(p, 1);
	else if (!ft_strncmp(minishell.shell->cmd, ".", 2) && !ft_strncmp(minishell.shell->cmd_args[1], ".", 2))
		ft_util_2(p, 2);
	else if (fd != -1)
		ft_util_1(minishell.shell->cmd_args, p, 1, &fd);
	else if ((!ft_strncmp(minishell.shell->cmd, "/", 1) || !ft_strncmp(minishell.shell->cmd, "./", 2))
		&& access(minishell.shell->cmd, X_OK) == 0)
		return (minishell.shell->cmd);
	else if (!ft_strncmp(minishell.shell->cmd, "/", 1) || !ft_strncmp(minishell.shell->cmd, "./", 2))
		ft_util_1(minishell.shell->cmd_args, p, 2, &fd);
	return (ckeck_path_cmd(minishell.shell->cmd, p->paths));
}

void	msg_error(t_minishell minishell, t_outils*exec, int n)
{
	if (n == 1)
	{
		write(2, "bash: ", 6);
		ft_putstr_fd(minishell.shell->cmd_args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (n == 2)
	{
		ft_putstr_fd(minishell.shell->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (n == 3)
	{
		ft_putstr_fd(minishell.shell->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	ft_free1(exec->paths);
	exit(127);
}

void execute1(t_minishell minishell, t_outils exec, t_env *my_env)
{
	exec.path = path_cmds("PATH=", ft_env);
	exec.paths = ft_split(exec.path, ':');
	if (exec.path == NULL)
		msg_error(minishell, 1, minishell.shell->cmd);
	if (minishell.shell->cmd == NULL)
		msg_error(minishell, 3, minishell.shell->cmd);
	if (!ft_strncmp(minishell.shell->cmd, "..", 2))
		msg_error(minishell, 2, minishell.shell->cmd);
	exec.cmd_path = check_cmd(minishell, my_env);
	if (exec.cmd_path == NULL)
		msg_error(minishell, 2, minishell.shell->cmd);
	execve(exec.cmd_path, minishell.shell->cmd_args, ft_env);
	error("execve");
}

void execute_one_cmd(t_minishell minishell, t_env *my_env, t_env *my_exp, t_outils exec)
{
    int pid;
    
    pid = fork();
    if (!builtins(minishell.shell->cmd_args, my_env, my_exp))
        execute1(minishell, exec, my_env);
}

void execution(t_minishell minishell, t_env *my_env, t_env *my_exp)
{
    int i;
    t_outils exec;
    
    i = 0;
    while (minishell.shell->full_commnad[i])
    {
        if (!minishell.shell->full_commnad[1])
          execute_one_cmd(minishell, my_env, my_exp, exec);
        else
            execute();        
    }
    
}
