/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:34:07 by wzahir            #+#    #+#             */
/*   Updated: 2024/07/15 19:43:18 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char *alphabet(void)
// {
//     char *str;
//     int i;

//     str = malloc(27 * sizeof(char));
//     if (!str)
//         return (NULL);
//     i = 0;
//     while(i < 26)
//     {
//         str[i] = 'a' + i;
//         i++;
//     }
//     str[i] = '\0';
//     return (str);
// }

// void ft_export(char **cmd, char **export)
// {
//     int i;
//     char *alpha;

//     i = 0;
//     alpha = alphabet();
//     if (ft_strcmp(cmd[1], "export") == 0)
//     {
//         while (alpha[i])
//         {
//             while (export[i])
//             {
//                 if (!ft_strncmp(&export[i][1], alpha + i, 1))
//                 {
//                     ft_putstr_fd("declare -x ", 1);
//                     ft_putstr_fd(export[i], 1);
//                     write(1, "\n", 1);
//                 }
//                 i++;
//             }
//             free(alpha);
//         }
//     }
// }

// int main (int ac, char **av, char **export)
// {
//     ft_export(av, export);
// }