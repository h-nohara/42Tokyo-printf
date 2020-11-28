#include "ft_printf.h"

t_plist *ft_init_plist()
{
    t_plist *lst;

    lst = (t_plist*)malloc(sizeof(t_plist));
    if (!lst)
        return (NULL);
    lst->flag_zero = 0;
    lst->flag_minus = 0;
    lst->width = -1;
    lst->precise = -1;
    lst->type = 0;
    return (lst);
}
