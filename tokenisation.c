#include "minishell.h"
// int cheak_quotes_paran(char *line)
// {
//     int i;
//     int singl_qu;
//     int double_qu;
//     int paran;
//     int j;

//     i = 0;
//     singl_qu = 0;
//     double_qu = 0;
//     paran = 0;

//     while (line[i])
//     {
//         if (line[i] == '\'')
//         {
//             if (double_qu % 2)
//                 j = singl_qu;
//             else
//                 singl_qu++;
//         }
//         if (line[i] == '\"')
//         {
//             if (singl_qu % 2)
//                 j = double_qu;
//             else
//                 double_qu++;
//         }
//         if (line[i] == '(')
//             paran++;
//         if (line[i] == ')')
//             paran--;
//         i++;
//     }
//     if (!(singl_qu % 2) && !(double_qu % 2) && !paran)
//         return (0);
//     return (1);
// }

// t_token *tokensation(char *line)
// {
//     t_token *my_token;
//     int i;
//     int is_symbol;

//     i = 0;
//     is_symbol = 0;
//     my_token = NULL;
//     while (line[i])
//     {
//         if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
//             i++;
//         else if (line[i] == '>' || line[i] == '<')
//         {
//             is_symbol = 1;
//             my_token = is_redirection(line, &i, my_token);
//         }
//         else if (line[i] == '|')
//         {
//             is_symbol = 1;
//             my_token = is_pipe(line, &i, my_token);
//         }
//         // else if (line[i] == '$')
//         // {
//         //     is_symbol = 1;
//         //     //is_var;
//         // }
//         else if (line[i] == '\'')
//         {
//             is_symbol = 1;
//             my_token = is_singl_qu(line, &i, my_token);
//         }
//         else if (line[i] == '\"')
//         {
//             is_symbol = 1;
//             my_token = is_double_qu(line, &i, my_token);
//         }
//         else
//         {
//             if (is_symbol == 0)
//             {
//                 my_token = is_cmd(line, &i, my_token);
//                 is_symbol = 1;
//             }
//         }
//     }
//     return (my_token);
// }
int white_spaces(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

char    *handel_quotes(char *input)
{
    char    quote;
    int i;
    
    i = 0;
    quote = input[i];
    i++;
    while (input[i] && input[i] != quote)
        i++;
    if(input[i] == quote)
        i++;
    return (&input[i]);

}

char    *handel_pipe_redir(char *input)
{
    char    symbol;
    int i;
    
    i = 0;
    symbol = input[i];
    i++;
    while (input[i] == symbol)
        i++;
    return(&input[i]);
}

char    *handel_prnt(char *input)
{
    int i;
    
    i = 0;
    return (&input[i]);
}

char    *handel_normal_arg(char *input)
{
  int i;
    
    i = 0;
    while (input[i] && !white_spaces(input[i]) && input[i] != '|' && input[i] != '&' && input[i] != '>' && input[i] != '<' && input[i] != '(' && input[i] != ')')
        {
            if (input[i] == 34 || input[i] == 39)
                input = handel_quotes(input);
            else
                i++;
        }
        return (&input[i]);
}

int count_tokens(char *input)
{
    int count;
    
    count = 0;
    while (white_spaces(*input))
        input++;
    if(!*input)
        return (0);
    while (*input)
    {
        if (*input == 34 || *input == 39) 
            input = handel_quotes(input);
        else if (*input == '|' || *input == '&' || *input == '>' || *input == '<')
            input = handel_pipe_redir(input);
        else if (*input == '(' || *input == ')')
            input = handel_prnt(input);
        else
            input = handel_normal_arg(input);
        while (white_spaces(*input))
            input++;
        count++;
    }
    return (count);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------

char    *cpy_pipe_redir(char **input)
{
    char    symbol;
    int     i;
    char    *token;

    i = 0;
    symbol = **input;
    while ((*input)[i] == symbol)
        i++;
    token = malloc(i + 1);
    i = 0;
    while  (**input == symbol)
    {
        token[i++] = **input;
        (*input)++;
    }
    token[i] = '\0';
    return (token);
}

char *cpy_prnt(char **input)
{
    char    *token;
    
    token = malloc(2);
    token[1] = **input;
    token[2] = '\0';
    (*input)++;
    return (token);
}

int arg_size(char *input)
{
    int     i;
    char	quote;

    i = 0;
    while (input[i] && input[i] != '|' && input[i] != '&' && input[i] != '>' && input[i] != '<' && input[i] != '(' && input[i] != ')')
    {
			i++;
    }
    return (i);
}

char    *cpy_normal_arg(char **input)
{
    int     i;
    char    *token;
    char    quote;

    i = 0;
    token = malloc(arg_size(*input));
    while (**input && !white_spaces(**input) && **input != '|' && **input != '&' && **input != '>' && **input != '<' && **input != '(' && **input != ')')
        {
            if (**input == 34 || **input == 39)
            {
                    quote = **input;
			        token[i++] = **input;
			        while (++(*input) && **input != quote)
				        token[i++] = **input;
                    if (**input)
                        token[i++] = *(*input)++;
                    continue;
            }
            token[i++] = **input;
            (*input)++;
        }
        token[i] = '\0';
        return (token);
}
char    **cpy_to_arr(char *input, char  **arr, int tokens)
{
    int j;

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

char    **tokensation(char *input)
{
    int     tokens;
    char    **arr;

    tokens = count_tokens(input);
    arr = malloc(sizeof(char *) * (tokens + 1));
    arr = cpy_to_arr(input, arr, tokens);
    return (arr);
}

// int main()
// {
//     char *tmp = "l\"asasdsd\"";
//     char **tab = tokensation(tmp);
//     int i = 0;
//     while (tab[i] != NULL)
//     {
//         printf("this is : %s\n ",tab[i]);
//         i++;
//         printf("%d\n", i);
//     }
//     return 0;
// }


