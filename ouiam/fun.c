/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:50:19 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/17 03:44:31 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// int    init_my_shell(t_shell *shell)
// {
//     char    *prompt;
    
//     prompt = ft_strdup("minishell $ ");
//     if (!prompt)
// 	{
// 		perror("Memory allocation error");
// 		return (-1);
// 	}
//     shell->prompt = prompt;
// 	return (0);
// }

void	read_sig_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
    rl_replace_line("", 0);
	rl_redisplay();
}

void    handling_signals(t_signal_status status)
{
    if (status == POS1)
    {
        signal(SIGINT, read_sig_handler);
		signal(SIGQUIT, SIG_IGN);
    }
}

void    read_user_cmd(t_shell *shell)
{
    char    *input;
    int     status;
    
    status = 1;
    while (status)
    {
        handling_signals(POS1);
        input = readline("minishell $ ");
        if (input)
        {
            add_history(input);
            printf("this is : %d\n ", cheak_quotes_paran(input));
            shell->tokens = tokensation(input);
            while (shell->tokens)
            {
                printf("\n\n my type is : %s and my value is %s", shell->tokens->type, shell->tokens->value);
                shell->tokens = shell->tokens->next;
            } 
        }
        if (!input)
            status = 0;
    }
}