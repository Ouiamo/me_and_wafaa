/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:19:45 by wzahir            #+#    #+#             */
/*   Updated: 2024/07/14 17:13:27 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


#define PATH_MAX        4096

int	ft_strcmp(const char *s1, const char *s2);
int	ft_strchr(const char *s, char c);
void ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, int n);

#endif 