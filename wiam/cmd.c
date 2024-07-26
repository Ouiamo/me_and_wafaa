#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (!(char)c)
		return ((char *) &s[i]);
	return (NULL);
}

t_token *is_cmd(char *line, int *i, t_token *my_token)
{
    int j;
    t_token *new_token;

    j = *i;
    while (line[*i] && !(ft_strchr("<>|$", line[*i])))
        (*i)++;
    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = ft_substr(line, j, *i - j);
    new_token->type = "cmd";
    new_token->next = NULL;
    ft_add_token_back(&my_token, new_token);
    return (new_token);
}