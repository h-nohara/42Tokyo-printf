/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:33:32 by hnohara           #+#    #+#             */
/*   Updated: 2021/01/05 17:30:52 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef	struct	s_params
{
	int		flag_zero;
	int		flag_minus;
	int		width;
	int		precise;
	char	type;
}				t_params;

typedef	struct	s_fmt_len_info
{
	int len_all;
	int len_org;
	int len_org_conv;
	int len_zero_padding;
	int len_padding;
}				t_fmt_len_info;

/*
** ft_printf
*/

int				ft_printf(char *fmt, ...);
int				ft_getarg_format_print(t_params *params, va_list *args);
int				ft_format(char *param_str, t_params *params, int is_cnull);
void			ft_print_nonnull_result(char *res, int is_cnull, int *count);
char			*ft_proc_format(char *s, va_list *va, int *count);

/*
** ft_va_arg_wrapper
*/
char			*ft_get_arg(char type, va_list *args, int *has_null);
char			*ft_va_arg_s(va_list *args);
char			*ft_va_arg_p(va_list *args);

/*
** plist_util
*/
t_params		*ft_init_params();

/*
** string_util
*/
char			ft_is_format_code(char c);
char			*ft_ctos(char c);
char			*ft_concat_padding(char *s, size_t len, char c, int is_left);
int				ft_hex_is_zero(char *s);

/*
** long_itoa
*/
char			*ft_long_itoa(long n);

/*
** detection
*/
char			*ft_detect_percent(char *s, int *count);
char			*ft_detect_flag(char *s, t_params *params);
char			*ft_detect_width(char *s, t_params *params, va_list *args);
char			*ft_detect_precise(char *s, t_params *p, va_list *args);

/*
** format str
*/
t_fmt_len_info	*info_new();
char			*ft_format_str(char *param_str, t_params *params);
char			*ft_format_str_joinpad(char *s, t_params *p, int len_pad);
void			ft_get_len_s(t_params *params, t_fmt_len_info *info);
char			*convert_org_str(char *s, t_fmt_len_info *info);

/*
** format cnull
*/
char			*ft_format_cnull(t_params *params);
char			*ft_concat_padding_cnull(int width, int is_left, int is_zero);

/*
** format int
*/
char			*ft_format_int(char *param_str, t_params *params);
char			*ft_format_int_core(char *s, int w, int p, t_params *ps);
char			*ft_format_int_w(char *param_str, t_params *params);
char			*ft_format_int_p(char *param_str, t_params *params);

char			*ft_format_int_wp(char *param_str, t_params *params);
char			*ft_format_int_wp_core(char *s, int *len, int p, int n);

char			*ft_int_pad_zero(char *s, int len_zero_pad);
char			*ft_int_check_zero_precise(char *param_str, t_params *params);

/*
** format hex
*/
char			*ft_format_hex(char *param_str, t_params *params);
char			*ft_format_hex_core(char *s, int w, int prec, t_params *p);
char			*ft_format_hex_w(char *param_str, t_params *params);
char			*ft_format_hex_p(char *param_str, t_params *params);
char			*ft_format_hex_wp(char *param_str, t_params *params);

char			*ft_hex_check_zero_precise(char *param_str, t_params *params);

/*
** format ptr
*/
char			*ft_ptr_pad_zero(char *s, int len_zero_pad);
char			*ft_format_ptr(char *param_str, t_params *params);
char			*ft_get_base_ptr_str(char *param_str, int precise);

/*
** hex
*/
char			*ft_convert_to_hex(long n, int is_upper);

#endif
