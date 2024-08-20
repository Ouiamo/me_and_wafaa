/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:19:45 by wzahir            #+#    #+#             */
/*   Updated: 2024/08/20 12:44:35 by wzahir           ###   ########.fr       */
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

typedef struct s_env
{
	char            *key;
    char            *value;
	char			*envp;
	char			*export;
	struct s_env   	*next;
}	t_env;

typedef struct s_global
{
	t_env *my_env;
	t_env *my_exp;
	int	exit_status;
}		t_global;

extern t_global shell;

int	    	ft_strcmp(const char *s1, const char *s2);
int	    	ft_strchr(const char *s, char c);
void    	ft_putstr_fd(char *s, int fd);
int	    	ft_strncmp(const char *s1, const char *s2, int n);
t_env		*ft_lstnew(char *key, char *value, char *envp);
void		ft_lstadd_back(t_env **lst, t_env *new);
void		ft_strncpy(char **dst, const char *src, size_t size);
long long 	ft_atoi(const char *str);
char		*ft_strdup(char *s);
int 		ft_strlen(const char *s);
int			ft_isdigit(char c);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void 		free_node(t_env *my_env);
void		ft_lstdelone(t_env *lst);

void 		ft_cd(char **tokens, t_env *my_env);
void 		ft_echo(char **cmd);
void 		ft_env(char **tokens, t_env *my_env);
int			ft_export(t_env *my_exp, char ** cmd, t_env *my_env);
void 		ft_getenv(char **env, t_env **my_env);
void		ft_pwd(void);
void		ft_exit(char **cmd);
void		ft_unset(t_env *my_env, t_env *my_exp, char **cmd);

void 		print_sorted_exp(t_env *my_exp);
char		*delete_quotes(char *str, char c);
int			equal_sign(char *str);

void 		my_export(t_env *my_env, t_env **my_exp);
int			exist_value(t_env *my_exp, char *key, char *value);
void 		env_from_exp(t_env **my_env, t_env *my_exp);
int			check_valid_identifier(char c);
int			check_arg(char *str);
int			export_error(char *c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void 		envp(t_env *my_env) ;


#endif 