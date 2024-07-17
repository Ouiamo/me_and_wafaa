/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:42:23 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/07/17 03:42:55 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_tokentype
{
	t_cmd,
	t_pipe,
	t_redirect_in,
	t_redirect_out,
	t_redirect_append,
	t_heredoc,
	t_file,
}						t_tokentype;

typedef struct s_token
{
	char			*value;
	char			*type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_shell
{
	char		*prompt;
	char		*user_input;
	t_token	*tokens;
}								t_shell;

typedef enum e_signal_status
{
	DEFAULT,
	POS1,
	IGNORE,
}		t_signal_status;

//libft funtions:
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, int start, size_t len);

//minishell functions:
void    read_user_cmd(t_shell *shell);
int cheak_quotes_paran(char *line);
t_token *tokensation(char *line);
t_token is_redirection(char *line, int *i, t_token *my_token);
void    ft_add_token_back(t_token **my_token, t_token *new_token);
t_token ft_last_token(t_token *my_token);
t_token is_singl_qu(char *line, int *i, t_token my_token);
t_token is_double_qu(char *line, int *i, t_token my_token);
t_token is_cmd(char *line, int *i, t_token my_token);
#endif