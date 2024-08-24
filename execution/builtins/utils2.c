/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:12:05 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:31:55 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"


int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*d;
	size_t	i;

	if (!s)
		return (NULL);
	d = malloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void free_node(t_env *my_env)
{
     while (my_env)
    {
        t_env *tmp = my_env;
        my_env = my_env->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}

long long	ft_atoi(const char *str)
{
	int			i;
	long double	nb;
	int			s;

	nb = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * s);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int main()
// {
// 	printf("%LF", ft_atoi("-9223372036854775809"));
// }