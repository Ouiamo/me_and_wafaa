/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:02:16 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/18 13:45:55 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void envp(t_env *my_env) 
// {
//     int i = 0;
//     char *tmp;

//     t_env *current = my_env;
//     int count = 0;
//     while (current) 
//     {
//         count++;
//         current = current->next;
//     }
//     if (my_env) 
//     {
//         my_env->envp = malloc(sizeof(char *) * (count + 1));
//         if (!my_env->envp) 
//         {
//             perror("malloc failed");
//             return;
//         }
//         current = my_env;
//         while (current) 
//         {
//             tmp = ft_strjoin(current->key, "=");
//             my_env->envp[i] = ft_strjoin(tmp, current->value);
//             free(tmp);
//             current = current->next;
//             i++;
//         }
//         my_env->envp[i] = NULL;
//     }
// }

void envp(t_env *my_env) 
{
    char *tmp;
    
    my_env->export = NULL;
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

    i = 0;
    while (env[i] && ft_strchr(env[i], '='))
    {
        j = 0;
        while (env[i][j] != '=')
            j++;
        key = (char *)malloc(j + 1);
        if(!key)
            return ;
        j = 0;
        while(env[i][j] != '=')
        {
            key[j] = env[i][j];
            j++;
        }
        key[j] = '\0';
        value = ft_strdup(&env[i][j + 1]);
        node = ft_lstnew(key, value);
        ft_lstadd_back(my_env, node);
        i++;
    }
    envp(*my_env);
    //free_node(*my_env);
    // while(*my_env)
    // {
    //     printf("key : %s\n  value : %s\n ", (*my_env)->key, (*my_env)->value);
    //     *my_env=(*my_env)->next;
    // }
}

void ft_env(char **tokens, t_env *my_env)
{
    int i;

    if (!tokens[1])
    {
        i = 0;
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

// int main(int ac, char **av, char **env)
// {
//     if (ac < 2) 
//     {
//         printf("Usage: %s env\n", av[0]);
//         return 1;
//     }
//     ft_env(av, env);
//     return 0;
// }
