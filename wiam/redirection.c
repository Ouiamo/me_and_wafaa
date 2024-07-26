#include "minishell.h"

t_token *ft_last_token(t_token *my_token)
{
    t_token *last;

    last = my_token;
    if(last)
        while(last->next)
            last = last->next;
    return (last);
}

void    ft_add_token_back(t_token **my_token, t_token *new_token)
{
    t_token *last;
    if (my_token)
    {
        last = *my_token;
        if(*my_token)
        {
            last = ft_last_token(last);
            last->next = new_token;
        }
        else
        {
            last = new_token;
        }
    }
}

t_token *is_redirection(char *line, int *i, t_token *my_token)
{
    t_token *new_token;
    int     j;

    j = *i;
    if (line[*i] == '>' && line[*i + 1] == '>')
        *i += 2;
    if (line[*i] == '<' && line[*i + 1] == '<')
        *i += 2;
    else
        (*i)++;
    //printf("i = %d\n", *i);
    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = ft_substr(line, j, *i - j);
    new_token->type = "redir";
    new_token->next = NULL;
    ft_add_token_back(&my_token, new_token);
    return (new_token);
}