/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:33:32 by hnohara           #+#    #+#             */
/*   Updated: 2020/12/15 21:08:47 by hnohara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

typedef	struct	s_str_lst
{
	char				*s;
	int				has_null;
	struct	s_str_lst	*next;
}					t_str_lst;

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
char			ft_is_format_code(char c);
char			*ft_format(char *param_str, t_params *params, int is_cnull);
char			*ft_get_arg(char type, va_list *args, int *has_null);
char			*ft_proc_format(char *s, t_str_lst **lst, va_list *va);

/*
** ft_va_arg_wrapper
*/
char			*ft_va_arg_s(va_list *args);
char			*ft_va_arg_p(va_list *args);

/*
** plist_util
*/
t_params			*ft_init_params();

/*
** tlist_util
*/
void			ft_free_one(void *content);
void			ft_free_strlst(t_str_lst *lst);
int				ft_strlst_append(t_str_lst **lst, char *s, int has_null);
int				ft_print_iter(t_str_lst *lst);

/*
** string_util
*/
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
char			*ft_detect_percent(char *s, t_str_lst **lst);
char			*ft_detect_flag(char *s, t_params *params);
char			*ft_detect_width(char *s, t_params *params, va_list *args);
char			*ft_detect_precise(char *s, t_params *p, va_list *args);

/*
** format str
*/
t_fmt_len_info	*info_new();
char			*ft_format_str(char *param_str, t_params *params);
void			ft_get_len_s(t_params *params, t_fmt_len_info *info);
char			*convert_org_str(char *s, t_fmt_len_info *info);

/*
** format cnull
*/
char			*ft_format_cnull(char *param_str, t_params *params);
char			*ft_concat_padding_cnull(int width, int is_left, int is_zero);

/*
** format int
*/
char			*ft_int_pad_zero(char *s, int len_zero_pad);
char			*ft_format_int(char *param_str, t_params *params);
char			*ft_int_check_zero_precise(char *param_str, t_params *params);
char			*ft_format_int_w(char *param_str, t_params *params);
char			*ft_format_int_p(char *param_str, t_params *params);
char			*ft_format_int_wp(char *param_str, t_params *params);

/*
** format hex
*/
char			*ft_format_hex(char *param_str, t_params *params);
char			*ft_hex_check_zero_precise(char *param_str, t_params *params);
char			*ft_format_hex_w(char *param_str, t_params *params);
char			*ft_format_hex_p(char *param_str, t_params *params);
char			*ft_format_hex_wp(char *param_str, t_params *params);

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

/*
** strlst_basic
*/
t_str_lst	*ft_strlst_new(char *s, int has_null);
t_str_lst	*ft_strlst_last(t_str_lst *lst);
void	ft_strlst_add_back(t_str_lst **lst, t_str_lst *new);
void	ft_strlst_clear(t_str_lst **lst, void (*del)(void*));

#endif
