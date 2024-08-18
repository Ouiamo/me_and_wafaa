#include "minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

void    free_my_collector(t_list *my_collector)
{
    t_list  *tmp;
    tmp = my_collector;
    while (tmp)
    {
        my_collector = my_collector->next;
        if (tmp->content)
            free(tmp->content);
        free(tmp);
        tmp = my_collector;
    }
}

void    free_spicial_ptr(t_list *my_collector, void *p)
{
    t_list  *tmp1;
    t_list  *tmp2;


    tmp1 = my_collector;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        if (tmp2->content == p)
        {
            tmp1->next = tmp2->next;
            free(tmp2->content);
            free (tmp2->next);
            return;
        }
        tmp1 = tmp1->next;
    }
    printf("this ptr doesn't exist\n");
}

void    *add_to_my_collector(t_list *my_collector, int size)
{
    t_list  *new_node;
    t_list  *tmp;

    tmp = my_collector;
    while (tmp->next)
        tmp = tmp->next;
    new_node = malloc(sizeof(t_list));
    //ft_memset(new_node, 0, sizeof(t_list));
    if (!new_node)
        free_my_collector(my_collector);
    new_node->content = malloc(size);
    //ft_memset(new_node->content, 0, size);
    if (!new_node->content)
        free_my_collector(my_collector);
    new_node->next = NULL;
    tmp->next = new_node;
    return (new_node->content);
}

void *ft_malloc(int size, void *p)
{
    static t_list *my_collector = 0;
    
    if (my_collector == 0)
    {
        my_collector = malloc(sizeof(t_list));
        if (!my_collector)
            printf("i can't allocat\n");
        my_collector->content = NULL;
        my_collector->next  = NULL;
    }
    if (size == -1)
        free_spicial_ptr(my_collector, p);
    else if (size == -2)
    {
        free_my_collector(my_collector);
        my_collector = 0;
    }
    else
        return(add_to_my_collector(my_collector, size));
    return (0);
}