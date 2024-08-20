/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:02:16 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 01:26:23 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void envp(t_env *my_env) 
{
    char *tmp;
    
    while (my_env) 
    {
        tmp = ft_strjoin(my_env->key, "=");
        my_env->envp = ft_strjoin(tmp, my_env->value);
        free(tmp);
        my_env = my_env->next;
    }
}

void ft_getenv(char **env, t_env **my_env)
{
    int i;
    int j;
    t_env *node;
    char *key;
    char *value;
    
    j = 0;
    i = 0;
    while (env[i])
    {
        j = ft_strchr(env[i], '=');
        key = ft_substr(env[i], 0, j);
        value = ft_substr(env[i], j + 1, ft_strlen(env[i]));
        node = ft_lstnew(key, value, NULL);
        ft_lstadd_back(my_env, node);
        i++;
    }
   // envp(*my_env);
    //free_node(*my_env);
    // while(*my_env)
    // {
    //     printf("key : %s\n  value : %s\n ", (*my_env)->key, (*my_env)->value);
    //     *my_env=(*my_env)->next;
    // }
}

void env_from_exp(t_env *my_env, t_env *my_exp)
{
	t_env *node;
	char *key;
    char *value;
    while (my_exp)
    {
        if (!my_exp->value)
           my_exp = my_exp->next;
        if (!my_exp)
            break;
        key = ft_strdup(my_exp->key);
       	value = ft_strdup(my_exp->value);
		node = ft_lstnew(key, value, NULL);
        ft_lstadd_back(&my_env, node);
        my_exp = my_exp->next;
    }
}

void ft_env(char **tokens, t_env *my_env)
{

    if (!tokens[1])
    {
        envp(my_env);
        while(my_env)
        {
            printf("%s\n", my_env->envp);
            my_env = my_env->next;
        }
    }    
    else
    {
        ft_putstr_fd("env: ˋ", 2);
        ft_putstr_fd(tokens[1], 2);
        ft_putstr_fd("': No such file or directory\n", 2);
    }
}

