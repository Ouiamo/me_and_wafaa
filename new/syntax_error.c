#include "minishell.h"

char    *cheak_prnt(char **arr)
{
    int prnt;

    prnt = 0;
    while (*arr)
    {
        if (**arr == '(')
            prnt++;
        else if (**arr == ')')
            prnt--;
        if (prnt < 0)
            return (")");
        arr++;
    }
    if (prnt > 0)
            return ("(");
    if (prnt < 0)
        return (")");
    return (0);
}

char    *first_cheak(char **arr)
{
    if (arr[0][0] == '\0')
        return ("arr is empty");
    if (arr[0][1] && arr[0][2])
        return (*arr);
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&' || **arr == '<' || **arr == '>' || **arr == '(' || **arr == ')'))
        return (*arr);
    return (NULL);
}

char    *second_cheak(char **arr)
{
    if (arr[0][0] == '\0')
        return ("arr is empty");
    if (arr[0][0] == '&' && !(arr[0][1]))
		return (*arr);
    if (arr[0][1] && arr[0][2])
        return (*arr);
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&' || **arr == ')'))
        return (*arr);
    return (NULL);

}

char    *third_cheak(char **arr)
{
    arr++;
    if (!*arr)
        return ("newline");
    else if (*arr && (**arr == '|' || **arr == '&'))
        return (*arr);
    return (NULL);
}

char    *cheak_cmd(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        if (arr[i][0] == '(' && i != 0 && arr[i - 1][0] != '|' && arr[i - 1][0] != '&' && arr[i - 1][0] != '>' && arr[i - 1][0] != '<' && arr[i - 1][0] != '(' && arr[i - 1][0] != ')')
        {
            i++;
            return (arr[i]);
        }
        else if (arr[i][0] == ')' && arr[i + 1][0] != '|' && arr[i + 1][0] != '&' && arr[i + 1][0] != '>' && arr[i + 1][0] != '<' && arr[i + 1][0] != '(' && arr[i + 1][0] != ')')
            return (arr[i + 1]);
        i++;
    }
    return (NULL);
}

char    *cheak_arr(char  **arr)
{
    char    *ptr;

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

int   syntax_error(char **arr)
{
    if (cheak_arr(arr))
    {
        printf("minishell: syntax error near unexpected token `%s'\n", cheak_arr(arr));
        return (1);
    }
    return (0);
}

// int main (int ac, char **av)
// {
//     if (ac > 1)
//     printf("%s\n", cheak_arr(av));
// }