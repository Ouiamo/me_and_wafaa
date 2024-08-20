/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:25:04 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 01:41:31 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_ARGUMENTS 100

t_global shell;

void read_command(char **input) {
    *input = readline("minishell> ");
    if (*input && **input) {
        add_history(*input);
    }
}

void parse_command(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \t\r\n\a");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[position] = NULL;
}

// void intial(void)
// {
//     shell.exit_status = 0;
//     shell.my_env = NULL;
//     shell.my_exp = NULL;
// }

int main(int ac, char **av, char **env) 
{
    char *input;
    char *args[MAX_ARGUMENTS];
    
    (void)ac;
    (void)av;
    t_env *my_env = NULL;
    t_env *my_exp = NULL;
    shell.exit_status = 0;
    ft_getenv(env, &my_env);
    my_export(my_env , &my_exp);
    while (1) 
    {
        read_command(&input);
        if (!input)
            break; // EOF (Ctrl+D)
        parse_command(input, args);
        if (strcmp(args[0], "exit") == 0)
            ft_exit(args);
        else if (strcmp(args[0], "cd") == 0)
            ft_cd(args, my_env);
        else if (strcmp(args[0], "echo") == 0)
            ft_echo(args);
        else if (strcmp(args[0], "env") == 0)
            ft_env(args, my_env);
        else if (strcmp(args[0], "export") == 0)
            ft_export(my_exp, args, my_env);
        else if (strcmp(args[0], "unset") == 0)
            ft_unset(my_env, my_exp, args);
        else if (strcmp(args[0], "pwd") == 0)
            ft_pwd();
        else
	    {
		    ft_putstr_fd(args[0], 2);
		    ft_putstr_fd(": command not found\n", 2);
		    return(127);
	    }
        free(input);
        
    }
    return 0;
}

