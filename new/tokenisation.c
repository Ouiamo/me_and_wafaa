/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:03:16 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:20:17 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	white_spaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	**tokensation(char *input)
{
	int		tokens;
	char	**arr;

	arr = NULL;
	tokens = count_tokens(input);
	printf("nbr of tokens : %d\n", tokens);
	if (tokens < 0)
		return (NULL);
	arr = ft_malloc(sizeof(char *) * (tokens + 1), 0);
	arr = cpy_to_arr(input, arr, tokens);
	return (arr);
}
