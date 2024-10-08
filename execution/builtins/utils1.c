/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:38:13 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/24 10:31:50 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	// if (!s1 && !s2) 
	// 	return (0);
    // if (!s1)
	// 	return (-1);
    // if (!s2)
	// 	return (1); 
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	if (fd != -1)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_strncpy(char **dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (src[i])
		{
			*dst[i] = src [i];
			i++;
		}
	}
	return ;
}

