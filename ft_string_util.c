#include "ft_printf.h"

char *ft_ctos(char c)
{
    char *s;

    s = (char*)malloc(sizeof(char) * 2);
    s[0] = c;
    s[1] = '\0';
    return (s);
}

char *ft_concat_padding(char *param_str, size_t len, char c, int pad_right)
{
    char *additional_str;
    char *res;

    additional_str = (char*)malloc(sizeof(char) * (len + 1));
    if (!additional_str)
        return (ft_strdup(param_str));
    additional_str = ft_memset(additional_str, c, len);
    additional_str[len] = '\0';

    if (pad_right == 0)
        res = ft_strjoin(additional_str, param_str);
    else
        res = ft_strjoin(param_str, additional_str);
    if (res)
        return (res);
    else
        return (ft_strdup(param_str));
}
