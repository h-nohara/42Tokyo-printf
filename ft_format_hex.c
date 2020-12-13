#include "ft_printf.h"

int ft_hex_is_zero(char *s)
{
    if (*s == '0' && ft_strlen(s) == 1)
        return (1);
    else
        return (0);
}

char *ft_format_hex(char *param_str, t_plist *params)
{
    int width;
    int precise;

    width = params->width;
    if (params->precise == 0)
    {
        if (ft_hex_is_zero(param_str) == 0)
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
    else if (params->precise == -2 && ft_hex_is_zero(param_str) == 1)
        param_str = "";
    precise = params -> precise;
    if (precise == -1)
    {
        if (width == -1)
            return (param_str);
        else
            return (ft_format_hex_w(param_str, params));
    }
    if (precise == -2)
    {
        if (width == -1)
            return (param_str);
        else
            return (ft_format_hex_w(param_str, params));
    }
    if (width == -1)
        return (ft_format_hex_p(param_str, params));
    else
        return (ft_format_hex_wp(param_str, params));
}

char *ft_hex_pad_zero(char *s, int len_zero_pad)
{
    if (ft_strlen(s) <= 0)
        return (s);
    return (ft_concat_padding(s, len_zero_pad, '0', 0));
}

char *ft_format_hex_w(char *param_str, t_plist *params)
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
            return (ft_hex_pad_zero(param_str, len_padding));
        return (ft_concat_padding(param_str, len_padding, ' ', params->flag_minus == 1));
    }
}

char *ft_format_hex_p(char *param_str, t_plist *params)
{
    int precise;
    int len;
    int len_zero_pad;

    precise = params->precise;
    len = ft_strlen(param_str);
    if (len >= precise)
        return (param_str);
    len_zero_pad = precise - len;
    return (ft_hex_pad_zero(param_str, len_zero_pad));
}

char *ft_format_hex_wp(char *s, t_plist *params)
{
    int precise;
    int len;

    precise = params->precise;
    len = ft_strlen(s);
    if (len < precise)
    {
        s = ft_concat_padding(s, precise - len, '0', 0);
        len = ft_strlen(s);
    }
    if (params->width <= len)
        return (s);
    else
        return (ft_concat_padding(s, params->width - len, ' ', params->flag_minus == 1));
}
