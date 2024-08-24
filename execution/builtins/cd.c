/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:12:14 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:30:24 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

void error(char *error)
{
    ft_putstr_fd("minishell: cd: ", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd(": No such file or directory\n", 2);
}

void change_value(t_env *my_env, char *key, char *new_value) 
{
    while (my_env) 
    {
        if (ft_strcmp(my_env->key, key) == 0)
        {
            free(my_env->value);
            my_env->value = ft_strdup(new_value);
            break;
        }
        my_env = my_env->next;
    }
}

void ft_cd(char **tokens, t_env *my_env) 
{
    char old_path[PATH_MAX];
    char new_path[PATH_MAX];
    char *old_pwd;
    char *pwd;
    
    old_pwd = getcwd(old_path, PATH_MAX);
    change_value(my_env, "OLDPWD", old_pwd);
    if (!tokens[1]) 
    {
        pwd = getenv("HOME");
        if (!pwd || chdir(pwd) < 0)
            error(pwd);
    } 
    else 
    {
        if (chdir(tokens[1]) < 0)
            error(tokens[1]);
    }
    pwd = getcwd(new_path, PATH_MAX);
    change_value(my_env, "PWD", pwd);
    envp(my_env);
    // t_env *temp = my_env;
    // while (temp) 
    // {
    //     printf("key: %s\nvalue: %s\n", temp->key, temp->value);
    //     temp = temp->next;
    // }
        //     while(my_env)
        // {
        //     printf("%s=%s\n", my_env->key, my_env->value);
        //     my_env = my_env->next;
        // }
}
