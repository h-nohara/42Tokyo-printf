#ifndef FT_PRINTF_H
 #define FT_PRINTF_H

#include <stdio.h>
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

typedef struct s_fmt_len_info
{
    int len_all;
    int len_org;
    int len_org_conv;
    int len_zero_padding;
    int len_padding;
} t_fmt_len_info;

t_fmt_len_info *info_new();

int ft_printf(char *fmt, ...);
char ft_is_format_code(char c);
char *ft_go_to_percent(char *s, t_list **lst);
char *ft_get_format_result(char *s, t_list **lst, va_list *args);
char *ft_translate_fmt(t_plist *plst, va_list *args);
char *ft_format_width_precise(char *s, t_plist *params);
char *ft_concat_padding(char *param_str, size_t len, char c, int is_left);

char *ft_va_arg_s(va_list *args);

t_plist *ft_init_params();

void ft_free_one(void *content);
void ft_clear_tlist(t_list *lst);
int ft_lst_append(t_list **lst, void *content);
int ft_print_iter(t_list *lst);

/* string_util */
char *ft_ctos(char c);

/* detection */
char *ft_detect_percent(char *s, t_list **lst);
char *ft_detect_flag(char *s, t_plist *params);
char *ft_detect_width(char *s, t_plist *params, va_list *args);
char *ft_detect_precise(char *s, t_plist *params, va_list *args);

/* get formatted length */
void get_block_len_str(t_plist *params, t_fmt_len_info *info);
void get_block_len_int(t_plist *params, t_fmt_len_info *info);

/* format */
char *convert_org_str(char *s, t_fmt_len_info *info);
char *ft_format_width_precise(char *param_str, t_plist *params);
char *ft_translate_fmt(t_plist *plst, va_list *args);

/* hex */
char *ft_convert_to_hex(int n, int is_upper);

#endif
