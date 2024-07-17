#include "minishell.h"
int cheak_quotes_paran(char *line)
{
    int i;
    int singl_qu;
    int double_qu;
    int paran;

    i = 0;
    singl_qu = 0;
    double_qu = 0;
    paran = 0;

    while (line[i])
    {
        if (line[i] == '\'')
            singl_qu++;
        if (line[i] == '\"')
            double_qu++;
        if (line[i] == '(')
            paran++;
        if (line[i] == ')')
            paran--;
        i++;
    }
    if (!(singl_qu % 2) && !(double_qu % 2) && !paran)
        return (0);
    return (1);
}

t_token *tokensation(char *line)
{
    t_token my_token;
    int i;
    int is_symbol;

    my_token
    i = 0;
    is_symbol = 0;
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '\t')
            i++;
        else if (line[i] == '>' || line[i] == '<')
        {
            is_symbol = 1;
            my_token = is_redirection(line, &i, my_token);
        }
        else if (line[i] == '|')
        {
            is_symbol = 1;
            my_token = is_pipe(line, &i, my_token);
        }
        else if (line[i] == '$')
        {
            is_symbol = 1;
            //is_var;
        }
        else if (line[i] == '\'')
        {
            is_symbol = 1;
            my_token = is_singl_qu(line, &i, my_token);
        }
        else if (line[i] == '\"')
        {
            is_symbol = 1;
            my_token = is_double_qu(line, &i, my_token);
        }
        else
        {
            if (is_symbol = 0)
            {
                my_token = is_cmd(line, &i, my_token);
                is_symbole = 1;
            }
        }
    }
    return (my_token);
}

// int main() {
//     char *tmp = "'This is a string with a \"double quote\" inside a single quote'";
//     printf("this is : %d\n ", cheak_quotes_paran(tmp));
//     return 0;
// }
