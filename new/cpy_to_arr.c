/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:17:51 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:21:20 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cpy_pipe_redir(char **input)
{
	char	symbol;
	int		i;
	char	*token;

	i = 0;
	symbol = **input;
	while ((*input)[i] == symbol)
		i++;
	token = ft_malloc(i + 1, 0);
	i = 0;
	while (**input == symbol)
	{
		token[i++] = **input;
		(*input)++;
	}
	token[i] = '\0';
	return (token);
}

char	*cpy_prnt(char **input)
{
	char	*token;

	token = ft_malloc(2, 0);
	token[0] = **input;
	token[1] = '\0';
	(*input)++;
	return (token);
}

int	arg_size(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !white_spaces(input[i]) && input[i] != '|'
		&& input[i] != '&' && input[i] != '>' && input[i] != '<'
		&& input[i] != '(' && input[i] != ')')
		i++;
	return (i);
}

char	*cpy_normal_arg(char **input)
{
	int		i;
	char	*token;
	char	quote;

	i = 0;
	token = ft_malloc(arg_size(*input) + 1, 0);
	while (**input && !white_spaces(**input) && **input != '|' && **input != '&'
		&& **input != '>' && **input != '<' && **input != '(' && **input != ')')
	{
		if (**input == 34 || **input == 39)
		{
			quote = **input;
			token[i++] = **input;
			while (++(*input) && **input != quote)
				token[i++] = **input;
			if (**input)
				token[i++] = *(*input)++;
			continue ;
		}
		token[i++] = **input;
		(*input)++;
	}
	token[i] = '\0';
	return (token);
}

char	**cpy_to_arr(char *input, char **arr, int tokens)
{
	int	j;

	j = 0;
	while (white_spaces(*input))
		input++;
	while (*input && j < tokens)
	{
		if (*input == '|' || *input == '&' || *input == '>' || *input == '<')
			arr[j] = cpy_pipe_redir(&input);
		else if (*input == '(' || *input == ')')
			arr[j] = cpy_prnt(&input);
		else
			arr[j] = cpy_normal_arg(&input);
		while (white_spaces(*input))
			input++;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
