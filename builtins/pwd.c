/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:08:57 by wzahir            #+#    #+#             */
/*   Updated: 2024/07/15 09:36:16 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        exit_with_status(1);
    }
    exit_with_status(0);
}
