#ifndef FT_PRINTF_H
 #define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_plist
{
    int flag_zero;
    int flag_minus;
    int width;
    int precise;
    char type;
} t_plist;

void ft_printf(char *fmt, ...);
char ft_is_format_code(char c);
int ft_go_to_percent(char *s, t_list **lst);
int ft_get_format_result(char *s, t_list **lst, va_list *args);
char *ft_translate_fmt(t_plist *plst, va_list *args);
char *ft_format_width_precise(char *s, t_plist *params);
char *ft_concat_padding(char *param_str, size_t len, char c, int is_left);

t_plist *ft_init_plist();

void ft_free_one(void *content);
void ft_clear_tlist(t_list *lst);
int ft_lst_append(t_list **lst, void *content);
void ft_print_iter(t_list *lst);

char *ft_ctos(char c);

#endif
