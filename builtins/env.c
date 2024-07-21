/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:02:16 by wzahir            #+#    #+#             */
/*   Updated: 2024/07/18 21:42:49 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_env(char **cmd, char **env)
{
    int i;

    i = 0;
    if (ft_strcmp(cmd[1], "env") == 0 && !cmd[2])
    {
        while (env[i] && ft_strchr(env[i], '='))
        {
            ft_putstr_fd(env[i], 1);
            write(1, "\n", 1);
            i++;
        }
    }
    else
    {
    	write(2, "env: ", 5);
        write(2, "'", 1);
		ft_putstr_fd(cmd[2], 2);
        write(2, "'", 1);
		ft_putstr_fd(": No such file or directory\n", 2); 
    }
}

// int main (int ac, char **av, char **env)
// {

//     ft_env(av, env);
// }