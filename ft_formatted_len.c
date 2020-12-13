#include "ft_printf.h"

t_fmt_len_info *info_new()
{
    t_fmt_len_info *info;

    info = (t_fmt_len_info*)malloc(sizeof(t_fmt_len_info));
    info->len_all = 0;
    info->len_org = 0;
    info->len_org_conv = 0;
    info->len_zero_padding = 0;
    info->len_padding = 0;
    return (info);
}

void get_block_len_str(t_plist *params, t_fmt_len_info *info)
{
    int len_org;
    int width;
    int precise;

    len_org = info->len_org;
    width = params->width;
    precise = params->precise;
    width = (width == -1) ? 0 : width;
    if (precise == -1)
        precise = len_org;
    else if (precise == -2 && params->type == 's')
        precise = 0;
    else if (precise == -2 && (params->type == 'c' || params->type == '%'))
        precise = 1;
    info->len_org_conv = (precise > len_org) ? len_org : precise;
    if (info->len_org_conv >= width)
    {
        info->len_all = info->len_org_conv;
        info->len_zero_padding = 0;
        info->len_padding = 0;
    } else {
        info->len_all = width;
        info->len_zero_padding = 0;
        info->len_padding = info->len_all - info->len_org_conv;
    }
}

char *ft_format_int(char *param_str, t_plist *params)
/* void get_block_len_int(t_plist *params, t_fmt_len_info *info, int is_neg) */
{
    int width;
    int precise;

    if (params->precise == 0)
    {
        if (param_str[0] != '0')
            params->precise = 1;
        else {
            if (params->width == -1)
                param_str = "";
            else
            {
                params->precise = 1;
                param_str = " ";
            }
        }
    }
    else if (params->precise == -2 && param_str[0] == '0')
    {
        param_str = "";
    }
    width = params->width;
    precise = params -> precise;
    if (precise == -1)
    {
        if (width == -1)
            return (param_str);
        else
            return (ft_format_int_w(param_str, params));
    }
    if (precise == -2)
    {
        if (width == -1)
            return (param_str);
        else
            return (ft_format_int_w(param_str, params));
    }
    if (width == -1)
        return (ft_format_int_p(param_str, params));
    else
        return (ft_format_int_wp(param_str, params));
}

char *ft_int_pad_zero(char *s, int len_zero_pad)
{
    if (ft_strlen(s) <= 0)
        return (s);
    if (*s == '-')
        return (ft_strjoin("-", ft_concat_padding(++s, len_zero_pad, '0', 0)));
    else
        return (ft_concat_padding(s, len_zero_pad, '0', 0));
}

char *ft_format_int_w(char *param_str, t_plist *params)
{
    int len;
    int len_padding;

    len = ft_strlen(param_str);
    if (len >= params->width)
        return (param_str);
    else
    {
        len_padding = params->width - len;
        if ((params->flag_zero == 1) && (params->flag_minus == 0))
            return (ft_int_pad_zero(param_str, len_padding));
        return (ft_concat_padding(param_str, len_padding, ' ', params->flag_minus == 1));
    }
}

char *ft_format_int_p(char *param_str, t_plist *params)
{
    int precise;
    int len_base;
    int is_neg;
    int len_zero_pad;

    precise = params->precise;
    is_neg = *param_str == '-';
    len_base = is_neg ? ft_strlen(param_str) - 1 : ft_strlen(param_str);
    if (len_base >= precise)
        return (param_str);
    len_zero_pad = precise - len_base;
    return (ft_int_pad_zero(param_str, len_zero_pad));
}

char *ft_format_int_wp(char *s, t_plist *params)
{
    int precise;
    int len;
    int len_base;
    int is_neg;

    precise = params->precise;
    is_neg = *s == '-';
    len = ft_strlen(s);
    len_base = is_neg ? len - 1 : len;
    if (len_base < precise)
    {
        if (is_neg == 1)
            s = ft_strjoin("-", ft_concat_padding(++s, precise - len_base, '0', 0));
        else
            s = ft_concat_padding(s, precise - len, '0', 0);
        len = ft_strlen(s);
    }
    if (params->width <= len)
        return (s);
    else
        return (ft_concat_padding(s, params->width - len, ' ', params->flag_minus == 1));
}
