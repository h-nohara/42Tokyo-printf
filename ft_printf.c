#include "ft_printf.h"
#include <stdio.h>

void ft_printf(char *fmt, ...)
{
    va_list args;
    t_list *lst;

    va_start(args, fmt);

    lst = ft_lstnew(ft_strdup(""));
    if (!lst)
        return ;
    while (1) {
        if ((fmt = ft_detect_percent(fmt, &lst)) == NULL)
            break ;
        if ((fmt = ft_get_format_result(fmt, &lst, &args)) == NULL)
            break ;
    }
    ft_print_iter(lst);
    /*ft_clear_tlist(lst);*/
}

char ft_is_format_code(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
        c == 'x' || c == 'X' || c == '%')
        return (c);
    return (0);
}


char *ft_get_format_result(char *s, t_list **lst, va_list *args)
{
    char *tmp;
    t_plist *params;

    if (*s != '%')
        return (NULL);
    params = ft_init_params();
    ++s;
    s = ft_detect_flag(s, params);
    s = ft_detect_width(s, params);
    s = ft_detect_precise(s, params);
    if (ft_is_format_code(*s))
        params->type = *(s++);
    else
        return (s);
    tmp = ft_translate_fmt(params, args);
    if (ft_lst_append(lst, tmp) == -1)
        return (NULL);
    return (s);
}

char *ft_format_width_precise(char *param_str, t_plist *params)
{
    t_fmt_len_info *info;
    char *converted_org;
    char *res;

    info = info_new();
    info->len_org = ft_strlen(param_str);
    if (params->type == 's' || params->type == '%')
        get_block_len_str(params, info);
    else
        get_block_len_int(params, info);
    converted_org = convert_org_str(param_str, info);
    if ((info->len_padding) > 0)
    {
        if ((params->type == 's' || params->type == 'c' || params->type == '%') && (params->flag_zero == 1))
            res = ft_concat_padding(converted_org, (size_t)(info->len_padding), '0', 1);
        else
            res = ft_concat_padding(converted_org, (size_t)(info->len_padding), ' ', 1);
    }
    else
        res = converted_org;
    return (res);
}

char *ft_translate_fmt(t_plist *params, va_list *args)
{
    char *param_str;
    char *res;

    if (params->type == 's')
        param_str = va_arg(*args, char*);
    else if (params->type == 'c')
        param_str = ft_ctos((char)va_arg(*args, int));
    else if (params->type == 'd' || params->type == 'i')
        param_str = ft_itoa(va_arg(*args, int));
    else if (params->type == 'u')
        param_str = ft_itoa(va_arg(*args, unsigned int));
    else if (params->type == 'x' || params->type == 'X')
        param_str = ft_convert_to_hex(va_arg(*args, int), params->type == 'X');
    else if (params->type == 'p')
        param_str = ft_strjoin("0x10", ft_convert_to_hex((int)va_arg(*args, int*), 0));
    else if (params->type == '%')
        param_str = ft_strdup("%");
    else
        param_str = ft_strdup("snord");
    res = ft_format_width_precise(param_str, params);
    return (res);
}

char *convert_org_str(char *s, t_fmt_len_info *info)
{
    int len_org;
    int len_org_conv;

    len_org = info->len_org;
    len_org_conv = info->len_org_conv;
    if (len_org_conv == len_org)
        return(ft_strdup(s));
    else if (len_org_conv < len_org)
    {
        return(ft_substr(s, 0, info->len_org_conv));
    } else {
        return(ft_concat_padding(s,  info->len_zero_padding, '0', 1));
    }
}
