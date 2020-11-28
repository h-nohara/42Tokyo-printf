#include "ft_printf.h"

void ft_free_one(void *content)
{
    /*free(content);*/
}

void ft_clear_tlist(t_list *lst)
{
    ft_lstclear(&lst, &ft_free_one);
}

int ft_lst_append(t_list **lst, void *content)
{
    t_list *new_lst;

    new_lst = ft_lstnew(content);
    if (!new_lst)
        return (-1);
    ft_lstadd_back(lst, new_lst);
    return (0);
}

void ft_print_iter(t_list *lst)
{
    while (lst)
    {
        ft_putstr_fd(lst->content, 1);
        lst = lst->next;
    }
    ft_putchar_fd('\n', 1);
}
