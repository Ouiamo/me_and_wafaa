#include "minishell.h"

int nbr_commands(char **arr)
{
    int i;

    i = 1;
    while (*arr)
    {
        if (**arr == '|' || **arr == '&')
            i++;
        arr++;
    }
    return (i);
}
void    initial_my_shell(t_minishell *minishell, char  **arr)
{
    int i ;

    i = nbr_commands(arr);
    minishell->shell = ft_malloc(sizeof(t_shell) * (i + 1), 0);
    while (i > -1)
    {
        minishell->shell[i].pipe_type = 0;
        minishell->shell[i].prnt = 0;
        minishell->shell[i].cmd = NULL;
        minishell->shell[i].flags = NULL;
        minishell->shell[i].full_commnad = NULL;
        i--;
    }
}

//----------------------------------------------------------------------------------------

t_shell add_pipetype(char   *arr, t_shell shell)
{
    if (arr[0] == '|' && arr[1])
        shell.pipe_type = 2;
    else if (arr[0] == '|')
        shell.pipe_type = 1;
    else
        shell.pipe_type = 3;
    return (shell);
}

t_shell add_prnt(char c, t_shell shell)
{
    if (c == '(')
        shell.prnt++;
    else if (c == ')')
        shell.prnt--;
    return (shell);
}

char    *remove_quotes(char *arr)
{
    int i;
    char quote;
    char *new;
    int j;

    quote = 0;
    i = -1;
    while (arr[++i])
        if (arr[i] == 39 || arr[i] == 34)
            quote = arr[i];
    if (quote)
        new = ft_malloc(i - 1, 0);
    else
        new = ft_malloc(i + 1, 0);
    i = 0;
    j = 0;
    while (arr[i])
    {
        if (arr[i] == 39 || arr[i] == 34)
            i++;
        else
            new[j++] = arr[i++];
    }
    new[j] = '\0';
    printf("mew = *%s*\n", new);
    return (new);
}

t_list  *add_flags(char *arr, t_shell shell)
{
    t_list  *new_flag;
    t_list  *tmp;

    new_flag = ft_malloc(sizeof(t_list), 0);
    new_flag->content = remove_quotes(arr);
    new_flag->next = NULL;
    if (!shell.flags)
        return (new_flag);
    tmp = shell.flags;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_flag;
    return(shell.flags);
}

t_shell add_cmd(char ***arr, t_shell shell)
{
    while (**arr)
    {
        if (***arr == '|' || ***arr == '&' || ***arr == '(' || ***arr == ')' || ***arr == '<' || ***arr == '>')
            break;
        if (!shell.cmd)
            shell.cmd = remove_quotes(**arr);
        else
            shell.flags = add_flags(**arr, shell);
        (*arr)++;
    }
    (*arr)--;
    return (shell);
}

t_shell add_in_file(char *redir, t_shell shell, char  *name)
{
     t_list  *new_file;
    t_list  *list_file;

    new_file = ft_malloc(sizeof(t_list), 0);
    list_file = shell.infiles;
    new_file = ft_malloc(sizeof(t_list), 0);
    list_file = shell.infiles;
    if(redir[1])
        printf("it's herdoc\n");
    else
        new_file->fd = open(name,O_RDONLY);
    if (new_file->fd < 0)
        printf("minishell: %s: No such file or directory\n", name);
    new_file->next = list_file;
    shell.infiles = new_file;
    return (shell);
}

t_shell add_out_file(char   *redir, t_shell shell, char *name)
{
    t_list  *new_file;
    t_list  *list_file;

    new_file = ft_malloc(sizeof(t_list), 0);
    list_file = shell.outfiles;
    if(redir[1])
        new_file->fd = open(name, O_CREAT, O_APPEND, O_RDONLY, 0644);
    else
        new_file->fd = open(name, O_CREAT, O_WRONLY, O_TRUNC, 0644);
    if (new_file < 0)
        printf("ERROR : we can not open %s\n", name);
    new_file->next = list_file;
    shell.outfiles = new_file;
    return (shell);
}

t_shell add_redir(char **arr, t_shell shell)
{
    char *my_redir;
    
    my_redir = *arr;
    arr++;
    if (my_redir[0] == '>')
        shell = add_out_file(my_redir, shell, *arr);
    if (my_redir[0] == '<')
        shell = add_in_file(my_redir, shell, *arr);
    return (shell);
}

void    creat_my_shell(t_minishell *minishell, char  **arr)
{
    int i;

    i = 0;
    while (*arr)
    {
        
        if (**arr == '|' || **arr == '&')
        {
            minishell->shell[i] = add_pipetype(*arr, minishell->shell[i]);
            i++;
        }
        else if (**arr == '(' || **arr == ')')
            minishell->shell[i] = add_prnt(**arr, minishell->shell[i]);
        else if (**arr == '<' || **arr == '>')
            minishell->shell[i] = add_redir(arr, minishell->shell[i]);
        // expand
        else
            minishell->shell[i] = add_cmd(&arr, minishell->shell[i]);
        arr++;
    }
    
}
//---------------------------------------------------------------------------------------------------

char    *my_join(char *s1, char *s2)
{
    int i;
    int j;
    char    *join;
    i = 0;
    j = 0;
    // printf ("this is s1 %s \n", s1);
    // printf ("this is s2 %s \n", s2);
    while (s1[i])
        i++;
    while (s2[j])
        j++;
    // printf("161\n");
    join = ft_malloc(i + j + 2, 0);
    i = 0;
    j = 0;
    while (s1[i])
        join[j++] = s1[i++];
    join[j++] = ' ';
    i = 0;
    while (s2[i])
        join[j++] = s2[i++];
    join[j] = '\0';
    return (join);
}

char    *join_my_command(t_shell shell)
{
    t_list  *flags;
    char    *my_command;
    char    *tmp;

    if (!shell.flags)
        return(shell.cmd);
    flags = shell.flags;
    my_command = my_join(shell.cmd, flags->content);
    flags = flags->next;
    while (flags)
    {
        tmp = my_command;
        my_command = my_join(my_command, flags->content);
        free(tmp);
        flags = flags->next;
    }
    return (my_command);
}


void    join_my_shell(t_minishell *minishell, int n)
{
    int i;
    i = 0;
    while (i < n)
    {
        minishell->shell[i].full_commnad = join_my_command(minishell->shell[i]);
        i++;
    }
}

void    parsing(t_minishell *minishell, char **arr)
{
    //printf("this is the cmd: %s \n %s\n", shell->cmd, arr[0]);
    initial_my_shell(minishell, arr);
    creat_my_shell(minishell, arr);
    join_my_shell(minishell, nbr_commands(arr));
}
// fd = open
// fd = -1
// acces(fd , F_OK)
// perror("")