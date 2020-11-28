#include "ft_printf.h"
#include <stdio.h>

void ft_printf(char *fmt, ...)
{
    va_list ap;
    t_list **lst;
    int res;

    printf("start\n");
    va_start(ap, fmt);

    *lst = ft_lstnew(ft_strdup(""));
    if (!(*lst))
        return ;
    while (1) {
        printf("go to percent\n");
        if ((res = ft_go_to_percent(fmt, lst)) == -1)
            break ;
        fmt += res;
        printf("get format\n");
        if ((res = ft_get_format_result(fmt, lst)) == -1)
            break ;
        fmt += res;
        if (!fmt)
            break ;
    }
    printf("go to finish\n");
    ft_print_iter(*lst);
    /*ft_clear_tlist(lst);*/
}

char ft_is_format_code(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'l' || c == 'u' ||
        c == 'x' || c == 'X' || c == '%')
        return (c);
    return (0);
}

int ft_go_to_percent(char *s, t_list **lst)
{
    int i;
    char *tmp;

    i = 0;
    while (s[i] && s[i] != '%')
        ++i;
    tmp = ft_substr(s, 0, i);

    if (ft_lst_append(lst, tmp) == -1)
        return (-1);
    return (i);
}

int ft_get_format_result(char *s, t_list **lst)
{
    int i;
    char *tmp;
    t_list *new_lst;
    t_plist *plst;

    if (*s != '%')
        return (-1);
    plst = ft_init_plist();
    i = 1;
    while (s[i] == '0' || s[i] == '-')
    {
        if (s[i] == '0')
            plst->flag_zero = 1;
        else
            plst->flag_minus = 1;
        ++i;
    }
    int start = i;
    while (ft_isdigit(s[i]))
        ++i;
    if (i != start)
        plst->width = ft_atoi(ft_substr(s + i, 0, i - start));
    if (s[i] == '.')
    {
        start = ++i;
        while (ft_isdigit(s[i]))
            ++i;
        if (i != start)
            plst->precise = ft_atoi(ft_substr(s + i, 0, i - start));
    }
    if (ft_is_format_code(s[i]))
        plst->type = s[i];

    tmp = ft_translate_fmt(plst);
    ++i;

    if (ft_lst_append(lst, tmp) == -1)
        return (-1);
    return (i);
}

char *ft_translate_fmt(t_plist *plst)
{
    return (ft_strdup("hohe"));
}
