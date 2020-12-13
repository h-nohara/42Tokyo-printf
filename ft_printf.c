#include "ft_printf.h"
#include <stdio.h>

int ft_printf(char *fmt, ...)
{
    va_list args;
    t_list *lst;

    va_start(args, fmt);

    lst = ft_lstnew(ft_strdup(""));
    if (!lst)
        return (-1);
    while (1) {
        if ((fmt = ft_detect_percent(fmt, &lst)) == NULL)
            break ;
        if ((fmt = ft_get_format_result(fmt, &lst, &args)) == NULL)
            break ;
    }
    return(ft_print_iter(lst));
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
    s = ft_detect_width(s, params, args);
    s = ft_detect_precise(s, params, args);
    if (ft_is_format_code(*s))
        params->type = *(s++);
    else
        return (s);
    tmp = ft_translate_fmt(params, args);
    if (ft_lst_append(lst, tmp) == -1)
        return (NULL);
    return (s);
}

char *ft_format_default(char *param_str, t_plist *params)
{
    t_fmt_len_info *info;
    char *converted_org;
    char *res;

    info = info_new();
    info->len_org = ft_strlen(param_str);
    get_block_len_str(params, info);
    converted_org = convert_org_str(param_str, info);
    if (info->len_padding <= 0)
        return (converted_org);
    else
        res = ft_concat_padding(converted_org, (size_t)(info->len_padding), ' ', params->flag_minus == 1);
    return (res);

}

char *ft_format(char *param_str, t_plist *params)
{
    char type;

    type = params->type;
    if (type == 's' || type == '%' || type == 'c')
        return (ft_format_str(param_str, params));
    else if (type == 'd' || type == 'i' || type == 'u')
        return (ft_format_int(param_str, params));
    else if (type == 'x' || type == 'X')
        return (ft_format_hex(param_str, params));
    else
        return (ft_format_default(param_str, params));
}

char *ft_va_arg_s(va_list *args)
{
    char *s;

    s = va_arg(*args, char*);
    if (!s)
        return ("(null)");
    else
        return (s);
}

char *ft_translate_fmt(t_plist *params, va_list *args)
{
    char *param_str;
    char *res;

    if (params->type == 's')
        param_str = ft_va_arg_s(args);
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
        param_str = ft_strdup("");
    res = ft_format(param_str, params);
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
        return (ft_substr(s, 0, info->len_org_conv));
    else
        return (ft_concat_padding(s,  info->len_zero_padding, '0', 0));
}
