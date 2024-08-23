/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:12:32 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:50:27 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cheak_arr(char **arr)
{
	char	*ptr;

	if (cheak_cmd(arr))
		return (cheak_cmd(arr));
	if (cheak_prnt(arr))
		return (cheak_prnt(arr));
	if (**arr == '|' || **arr == '&')
		return (*arr);
	while (*arr)
	{
		ptr = first_cheak(arr);
		if ((**arr == '>' || **arr == '<') && ptr)
			return (ptr);
		ptr = second_cheak(arr);
		if ((**arr == '|' || **arr == '&') && ptr)
			return (ptr);
		ptr = third_cheak(arr);
		if (**arr == '(' && ptr)
			return (ptr);
		if (*arr)
			arr++;
	}
	return (NULL);
}

int	syntax_error(char **arr)
{
	if (cheak_arr(arr))
	{
		printf("minishell: syntax error near unexpected token `%s'\n",
			cheak_arr(arr));
		return (1);
	}
	return (0);
}
