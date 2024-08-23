/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:42:23 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/08/23 11:46:22 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	int				fd;
	char			*herdoc;
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char	*full_commnad;
	char	*cmd;
	int		pipe_type;
	int		prnt;
	t_list	*flags;//args;
	t_list	*infiles;
	t_list	*outfiles;
}	t_shell;

typedef struct minishell
{
	int			exit_status;// tray to add this tatus to suntax error
	char		**env;
	t_shell		*shell;
}	t_minishell;


typedef enum e_signal_status
{
	POS1,
	DEFAULT,
	IGNORE,
}		t_signal_status;

//libft funtions:

char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, int start, size_t len);
size_t  ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
char	**free_memory(char **arr);

//minishell functions:

// void    read_user_cmd(char **env);
int white_spaces(char c);
void    read_user_cmd(char **env);
char **tokensation(char *input);
int	count_tokens(char *input);
char	**cpy_to_arr(char *input, char **arr, int tokens);
int    syntax_error(char **arr);
char	*cheak_prnt(char **arr);
char	*first_cheak(char **arr);
char	*second_cheak(char **arr);
char	*third_cheak(char **arr);
char	*cheak_cmd(char **arr);

int nbr_commands(char **arr);
void    parsing(t_minishell *minishell, char **arr);
void	creat_my_shell(t_minishell *minishell, char **arr);
t_shell	add_redir(char **arr, t_shell shell);
t_shell	add_cmd(char ***arr, t_shell shell);
t_shell	add_prnt(char c, t_shell shell);
t_shell	add_pipetype(char *arr, t_shell shell);
void	join_my_shell(t_minishell *minishell, int n);

void *ft_malloc(int size, void *p);


#endif
//cc -Wall -Wextra -Werror fun.c main.c tokenisation.c syntax_error.c libft1.c parsing.c  -lreadline
