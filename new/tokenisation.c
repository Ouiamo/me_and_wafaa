#include "minishell.h"
int white_spaces(char c)
{
    if (c == ' ' || c == '\t'   )
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
    if (input[i] != quote)
    {
        printf("UNCLOSED QUOTE\n");
        return (NULL);
    }
    else if(input[i] == quote)
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
    i++;
    return (&input[i]);
}

char    *handel_normal_arg(char *input)
{
  int i;
    
    i = 0;
    while (input[i] && !white_spaces(input[i]) && input[i] != '|' && input[i] != '&' && input[i] != '>' && input[i] != '<' && input[i] != '(' && input[i] != ')')
        {
            if (input[i] == 34 || input[i] == 39)
            {
                input = handel_quotes(&input[i]);
                if (!input)
                    return (NULL);
            }
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
        // if (*input == 34 || *input == 39) 
        // //     input = handel_quotes(input);
        // else 
        if (*input == '|' || *input == '&' || *input == '>' || *input == '<')
            input = handel_pipe_redir(input);
        else if (*input == '(' || *input == ')')
            input = handel_prnt(input);
        else
        {
            input = handel_normal_arg(input);
            if (!input)
                return (-1);
        }
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
    //printf("pipe i = %d && INPUT = %s\n", i, *input);
    token = ft_malloc(i + 1, 0);
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
    
    token = ft_malloc(2, 0);
    token[0] = **input;
    token[1] = '\0';
    (*input)++;
    return (token);
}

int arg_size(char *input)
{
    int     i;
    // char    quote;

    i = 0;
    // quote = 0;
    // printf ("input = %s\n", input);
    while (input[i] && !white_spaces(input[i]) && input[i] != '|' && input[i] != '&' && input[i] != '>' && input[i] != '<' && input[i] != '(' && input[i] != ')')
    {
        // if (input[i] == 34 || input[i] == 39)
        //     quote = input[i];
			i++;
    }
    // if (quote)
    // {
    //     if (i != 2)
    //         return (i - 2);
    //     return (1);
    // }
    return (i);
}

char    *cpy_normal_arg(char **input)
{
    int     i;
    char    *token;
    char    quote;

    i = 0;
    //printf("i = %d && INPUT = *%s*\n", arg_size(*input), *input);
    token = ft_malloc(arg_size(*input) + 1, 0);
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

    arr =  NULL;
    tokens = count_tokens(input);
    printf("nbr of tokens : %d\n", tokens);
    if (tokens < 0)
        return (NULL);
    arr = ft_malloc(sizeof(char *) * (tokens + 1), 0);
    arr = cpy_to_arr(input, arr, tokens);
    return (arr);
}

// int main()
// {
//     char *tmp = "hjk >> hfjhf \"fkhaf\" ja\"jkas\"afhj || && (djf) << aai >>>> && jd";
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


