/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:30:50 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:31:17 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

void	ft_pwd(void)
{
	char s[PATH_MAX];
    
    if (getcwd(s, PATH_MAX) != NULL)
    {
        ft_putstr_fd(s, 1);
        ft_putstr_fd("\n", 1);
    }
    else
    {
        ft_putstr_fd("Error getting current working directory\n", 2);
        //exit_status = 1;
    }
    //exit_status = 0;
}
