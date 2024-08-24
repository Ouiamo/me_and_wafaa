/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:23:28 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:30:55 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

int	is_str_digit(char	*args)
{
	int	i;

	i = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	if (args[i] == '\0')
		return (0);
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **cmd)
{
	ft_putstr_fd("exit\n", 2);
	if (!cmd[1])
		exit(EXIT_SUCCESS);
	else if (is_str_digit(cmd[1]) && !(ft_atoi(cmd[1]) < LLONG_MIN || ft_atoi(cmd[1]) > LLONG_MAX) && !cmd[2])
		exit(ft_atoi(cmd[1]));
	else if (is_str_digit(cmd[1]) && cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd[2], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(2);
	}
}

// int main(int ac, char **av)
// {
//     if (ac < 2) 
//     {
//         printf("Usage: %s exit <number>\n", av[0]);
//         return 1;
//     }
//     ft_exit(av);
//     return 0;
// }