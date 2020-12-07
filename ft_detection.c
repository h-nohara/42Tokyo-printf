#include "ft_printf.h"

char *ft_detect_percent(char *s, t_list **lst)
{
    char *start;
    char *tmp;

    start = s;
    while (*s && *s != '%')
        ++s;
    if (start != s)
    {
        tmp = ft_substr(start, 0, s - start);
        if (ft_lst_append(lst, tmp) == -1)
            return (NULL);
    }
    return (s);
}

char *ft_detect_flag(char *s, t_plist *params)
{
    while (*s == '0' || *s == '-')
    {
        if (*s == '0')
            params->flag_zero = 1;
        else
            params->flag_minus = 1;
        ++s;
    }
    return (s);
}

char *ft_detect_width(char *s, t_plist *params)
{
    char *start;

    start = s;
    while (ft_isdigit(*s))
        ++s;
    if (s != start)
        params->width = ft_atoi(ft_substr(start, 0, s - start));
    return (s);
}

char *ft_detect_precise(char *s, t_plist *params)
{
    char *start;

    if (*s == '.')
    {
        start = ++s;
        while (ft_isdigit(*s))
            ++s;
        if (s != start)
            params->precise = ft_atoi(ft_substr(start, 0, s - start));
    }
    return (s);
}
