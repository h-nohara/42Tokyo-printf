#include "ft_printf.h"

t_fmt_len_info *info_new()
{
    t_fmt_len_info *info;

    info = (t_fmt_len_info*)malloc(sizeof(t_fmt_len_info));
    info->len_all = 0;
    info->len_org = 0;
    info->len_org_filled = 0;
    info->len_org_filled_cut = 0;
    info->len_zero_padding = 0;
    info->len_padding = 0;
    return (info);
}

void get_block_len_all(t_plist *params, t_fmt_len_info *info)
{
    if (params->width != -1)
        info->len_all = params->width;
    else
    {
        if (params->precise == -1)
        {
            printf("here10\n");
            info->len_all = info->len_org;
        }
        else if (info->len_org <= params->precise)
        {
            if (params->type == 's' || params->type == 'c')
                info->len_all = info->len_org;
            else
                info->len_all = params->precise;
        }
        else
        {
            printf("here11\n");
            info->len_all = params->precise;
        }
    }
}

void get_block_len_org_filled(t_plist *params, t_fmt_len_info *info)
{
    if (params->precise == -1)
        info->len_org_filled = info->len_org;
    else
    {
        if (params->type == 's' || params->type == 'c')
        {
            if (params->precise >= info->len_org)
                info->len_org_filled = info->len_org;
            else
                info->len_org_filled = params->precise;
        }
        else
            info->len_org_filled = params->precise;
    }
}

void get_block_len_org_filled_cut(t_fmt_len_info *info)
{
    if (info->len_all < info->len_org_filled)
        info->len_org_filled_cut = info->len_all;
    else
        info->len_org_filled_cut = info->len_org_filled;
}

void get_block_len_padding(t_fmt_len_info *info)
{
    if (info->len_org_filled_cut < info->len_all)
        info->len_padding = (info->len_all) - (info->len_org_filled_cut);
    else
        info->len_padding = 0;

}
