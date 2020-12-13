#include "ft_printf.h"

char *ft_ptr_pad_zero(char *s, int len_zero_pad)
{
    if (ft_strlen(s) <= 0 || len_zero_pad <= 0)
        return (s);
    s = ft_strjoin("10", s);
    s = ft_concat_padding(s, len_zero_pad, '0', 0);
    s = ft_strjoin("0x", s);
    return (s);
}

char *ft_format_ptr(char *param_str, t_plist *params)
{
    int width;
    int precise;
    int len;

    width = params->width;
    precise = params->precise;
    if (ft_strlen(param_str) == 1 && param_str[0] == '0')
    {
        if (precise == -2 || precise == 0)
            param_str = "0x";
        else if (precise == -1)
            param_str = "0x0";
        else
            param_str = ft_concat_padding("0x", precise, '0', 1);
    } else {
        len = ft_strlen(param_str);
        if (precise > len + 2)
            param_str = ft_ptr_pad_zero(param_str, precise - (len + 2));
        else
            param_str = ft_strjoin("0x10", param_str);
    }
    len = ft_strlen(param_str);
    if (len >= width)
        return(param_str);
    else
        return (ft_concat_padding(param_str, width - len, ' ', params->flag_minus));
}
