/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:45:20 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:31:32 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

void my_export(t_env *my_env, t_env **my_exp)
{
	t_env *node;
	char *key;
    char *value;
	//char *envp;
    while (my_env)
    {
       	key = ft_strdup(my_env->key);
       	value = ft_strdup(my_env->value);
		//envp = ft_strdup(my_env->envp);
		node = ft_lstnew(key, value, NULL);
        ft_lstadd_back(my_exp, node);
        my_env = my_env->next;
    }
}

void swap(t_env *a, t_env *b) 
{
    char *tmp_key;
    char *tmp_value;

	tmp_key = a->key;
	tmp_value = a->value;
    a->key = b->key;
    a->value = b->value;
    b->key = tmp_key;
    b->value = tmp_value;
}

void sort_exp(t_env **my_exp) 
{
    int swapped;
    t_env *ptr1;
    t_env *lptr;
	
	lptr = NULL;
    if (!my_exp || !*my_exp) 
		return;

    while (1) 
	{
        swapped = 0;
        ptr1 = *my_exp;
        while (ptr1->next != lptr) 
		{
            if (ft_strcmp(ptr1->key, ptr1->next->key) > 0) 
			{
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        if (!swapped) 
			break;
    }
}

void print_sorted_exp(t_env *my_exp) 
{
	char *tmp;
	char *tmp1;
	t_env *head;

    sort_exp(&my_exp);
	head = my_exp;
	while (my_exp) 
    {
		if (!(my_exp->value))
			my_exp->export = ft_strdup(my_exp->key);
		else
		{
        	tmp = ft_strjoin(my_exp->key, "=\"");
			tmp1= ft_strjoin(tmp, my_exp->value);
			free(tmp);
        	my_exp->export = ft_strjoin(tmp1, "\"");
        	free(tmp1);
		}
		my_exp = my_exp->next;
    }
	while (head) 
	{
        printf("declare -x %s\n", head->export);
        head = head->next;
    }
}

int	export_error(char *c)
{
	ft_putstr_fd("minishell: export: ˋ", STDERR_FILENO);
	ft_putstr_fd(c, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
