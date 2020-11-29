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
        plst->width = ft_atoi(ft_substr(s + start, 0, i - start));
    if (s[i] == '.')
    {
        start = ++i;
        while (ft_isdigit(s[i]))
            ++i;
        if (i != start)
            plst->precise = ft_atoi(ft_substr(s + start, 0, i - start));
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
    char *param_str;
    char *res;

    if (plst->type == 's')
        param_str = "hohe";
    else if (plst->type == 'd')
        param_str = "123";
    else
        param_str = "snord";
    res = ft_format_width_precise(param_str, plst);
    return (res);
}

char *ft_format_width_precise(char *param_str, t_plist *params)
{
    int len_all;
    int len_org;
    int len_org_filled;
    int len_org_filled_cut;
    int len_zero_padding;
    int len_padding;

    len_org = ft_strlen(param_str);
    if (params->width != -1)
        len_all = params->width;
    else
    {
        if (params->precise == -1 || len_org <= params->precise)
        {
            printf("here10\n");
            len_all = len_org;
        }
        else
        {
            printf("here11\n");
            len_all = params->precise;
        }
    }
    if (params->precise == -1)
        len_org_filled = len_org;
    else
    {
        if (params->type == 's' || params->type == 'c')
        {
            if (params->precise >= len_org)
                len_org_filled = len_org;
            else
                len_org_filled = params->precise;
        }
        else
            len_org_filled = params->precise;
    }
    if (len_all < len_org_filled)
        len_org_filled_cut = len_all;
    else
        len_org_filled_cut = len_org_filled;
    if (len_org_filled_cut < len_all)
        len_padding = len_all - len_org_filled_cut;
    else
        len_padding = 0;

    char *converted_org;
    printf("len_org : %d, preciese : %d, len_all : %d, len_org_filled : %d\n", len_org, params->precise, len_all, len_org_filled);
    printf("param_str : %s, len_org_filled_cut : %d\n", param_str, len_org_filled_cut);
    if (len_org_filled_cut < len_org)
    {
        ft_putstr_fd("here1\n", 1);
        converted_org = ft_substr(param_str, 0, len_org_filled_cut);
    }
    else if (len_org_filled_cut > len_org)
    {
        ft_putstr_fd("here2\n", 1);
        len_zero_padding = len_org_filled_cut - len_org;
        converted_org = ft_concat_padding(param_str, len_zero_padding, '0', 1);
    } else {
        ft_putstr_fd("here3\n", 1);
        converted_org = param_str;
    }
    ft_putstr_fd("+++++ ", 1);
    ft_putstr_fd(converted_org, 1);
    ft_putstr_fd("\n", 1);
    char *res;
    if (len_padding > 0)
    {
        printf("start cancat_padding\n");
        printf("converted org : %s, len_padding : %d\n", converted_org, len_padding);
        res = ft_concat_padding(converted_org, (size_t)len_padding, ' ', 1);
    }
    else
    {
        printf("not start cancat_padding\n");
        res = converted_org;
    }
    ft_putstr_fd("----- ", 1);
    ft_putstr_fd(res, 1);
    ft_putstr_fd("\n", 1);
    return (res);
}

char *ft_concat_padding(char *param_str, size_t len, char c, int is_left)
{
    char *additional_str;
    char *res;

    additional_str = (char*)malloc(sizeof(char) * (len + 1));
    if (!additional_str)
        return (ft_strdup(param_str));
    additional_str = ft_memset(additional_str, c, len);
    additional_str[len] = '\0';

    if (is_left == 1)
        res = ft_strjoin(additional_str, param_str);
    else
        res = ft_strjoin(param_str, additional_str);
    if (res)
        return (res);
    else
        return (ft_strdup(param_str));
}
