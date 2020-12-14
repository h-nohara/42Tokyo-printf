/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:33:32 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/14 16:33:36 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

typedef	struct	s_plist
{
    int flag_zero;
    int flag_minus;
    int width;
    int precise;
    char type;
}					t_plist;

typedef	struct	s_fmt_len_info
{
    int len_all;
    int len_org;
    int len_org_conv;
    int len_zero_padding;
    int len_padding;
}					t_fmt_len_info;

t_fmt_len_info		*info_new();

int				ft_printf(char *fmt, ...);
char				ft_is_format_code(char c);
char				*ft_go_to_percent(char *s, t_list **lst);
char				*ft_get_format_result(char *s, t_list **lst, va_list *args, t_list **has_null);

char				*ft_concat_padding(char *param_str, size_t len, char c, int is_left);

char				*ft_va_arg_s(va_list *args);

t_plist			*ft_init_params();

void				ft_free_one(void *content);
void				ft_clear_tlist(t_list *lst);
int				ft_lst_append(t_list **lst, void *content);
int				ft_print_iter(t_list *lst, t_list *has_null);

/* string_util */
char				*ft_ctos(char c);

/* long_itoa */
char				*ft_long_itoa(long n);

/* detection */
char				*ft_detect_percent(char *s, t_list **lst);
char				*ft_detect_flag(char *s, t_plist *params);
char				*ft_detect_width(char *s, t_plist *params, va_list *args);
char				*ft_detect_precise(char *s, t_plist *params, va_list *args);

/* get formatted length */
void				get_block_len_str(t_plist *params, t_fmt_len_info *info);

/* format */
char				*convert_org_str(char *s, t_fmt_len_info *info);
char				*ft_format(char *param_str, t_plist *params);
char				*ft_translate_fmt(t_plist *plst, va_list *args, char *is_contain_null);

/* format str */
char				*ft_format_str(char *param_str, t_plist *params);

/* format int */
char				*ft_int_pad_zero(char *s, int len_zero_pad);
char				*ft_format_int(char *param_str, t_plist *params);
char				*ft_int_check_zero_precise(char *param_str, t_plist *params);
char				*ft_format_int_w(char *param_str, t_plist *params);
char				*ft_format_int_p(char *param_str, t_plist *params);
char				*ft_format_int_wp(char *param_str, t_plist *params);

/* format hex */
int				ft_hex_is_zero(char *s);
char				*ft_hex_pad_zero(char *s, int len_zero_pad);
char				*ft_format_hex(char *param_str, t_plist *params);
char				*ft_hex_check_zero_precise(char *param_str, t_plist *params);
char				*ft_format_hex_w(char *param_str, t_plist *params);
char				*ft_format_hex_p(char *param_str, t_plist *params);
char				*ft_format_hex_wp(char *param_str, t_plist *params);

/* format ptr */
char				*ft_ptr_pad_zero(char *s, int len_zero_pad);
char				*ft_format_ptr(char *param_str, t_plist *params);
char				*ft_get_base_ptr_str(char *param_str, int precise);

/* hex */
char				*ft_convert_to_hex(long n, int is_upper);

#endif
