#include "ft_printf.h"

void ft_free_one(void *content)
{
    if (!content)
        return ;
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

int ft_print_iter(t_list *lst, t_list *has_null)
{
    int n;
    char *s;
    int len;
    char c;

    n = 0;
    /* write(fd, s, len); */
    while (lst)
    {
        s = (char*)(lst->content);
        ft_putstr_fd(s, 1);
        len = ft_strlen(lst->content);
        n += len;
        if (((char*)(has_null->content))[0] == 'y')
        {
            c = '\0';
            write(1, &c, 1);
            s += len + 1;
            ft_putstr_fd(s, 1);
            n += ft_strlen(s);
        }
        lst = lst->next;
        has_null = has_null->next;
    }
    return (n);
}
