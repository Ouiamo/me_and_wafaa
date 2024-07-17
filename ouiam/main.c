/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:41:38 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/17 03:28:11 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av)
{
    t_shell *shell;
    // if (init_my_shell(shell) == -1)
    //     return (0);
    read_user_cmd(shell);
    return (0);
}