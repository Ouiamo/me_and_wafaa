#include "minishell.h"

t_token *is_pipe(char *line, int *i, t_token *my_token)
{
    t_token *new_token;
    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = ft_substr(line, *i, 1);
    new_token->type = "pipe";
    new_token->next = NULL;
    ft_add_token_back(&my_token, new_token);
    (*i)++;
    return (new_token);
}