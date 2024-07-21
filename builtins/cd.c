/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:12:14 by wzahir            #+#    #+#             */
/*   Updated: 2024/07/21 23:56:06 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_cd(char **cmd)
{
    char old_path[PATH_MAX];
    char new_path[PATH_MAX];
    char *o_path;
    char *n_path;

    if (!cmd[1])
        cd_only();
    o_path = getcwd(old_path, PATH_MAX);
    if (chdir(cmd[1]) < 0)
        return;
    n_path = getcwd(new_path, PATH_MAX);  
}
//https://github.dev/fraqioui/minishell
// https://github.dev/achrafelkhnissi/minishell
// https://42-cursus.gitbook.io/guide/rank-03/minishell/functions
// https://github.dev/paulahemsi/minishell