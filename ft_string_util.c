#include "ft_printf.h"

char *ft_ctos(char c)
{
    char *s;

    s = (char*)malloc(sizeof(char) * 2);
    s[0] = c;
    s[1] = '\0';
    return (s);
}
