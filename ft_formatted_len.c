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
    precise = params -> precise;
    width = (width == -1) ? len_org : width;
    precise = (precise == -1) ? len_org : precise;
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

void get_block_len_int(t_plist *params, t_fmt_len_info *info)
{
    int len_org;
    int width;
    int precise;

    len_org = info->len_org;
    width = params->width;
    precise = params -> precise;
    width = (width == -1) ? len_org : width;
    precise = (precise == -1) ? len_org : precise;
    if (precise <= len_org)
    {
        info->len_org_conv = len_org;
        info->len_zero_padding = 0;
    } else {
        info->len_org_conv = precise;  /* (zero_pad + org) and cut */
        info->len_zero_padding = precise - len_org;
    }
    if (precise >= width)
    {
        info->len_all = info->len_org_conv;
        info->len_padding = 0;
    } else {
        info->len_all = width;
        info->len_padding = width - info->len_org_conv;
    }
}
