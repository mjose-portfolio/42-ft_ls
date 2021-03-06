/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 04:54:59 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 21:28:21 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**display_dirlnk_for_rec_ft(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_no_flags(parms);
		tab_dirs = print_list_lnk_rec(list_dirlnk_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_rec(list_dirlnk_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dirlnk_for_rec_def(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_no_flags(parms);
		tab_dirs = print_list_lnk_rec(list_dirlnk_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_rec(list_dirlnk_fa(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_frtl(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_fl(parms);
		tab_dirs = print_list_flr_rec(list_dir_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fal(parms);
		tab_dirs = print_list_flr_rec(list_dir_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_ftl(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_fl(parms);
		tab_dirs = print_list_fl_rec(list_dir_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fal(parms);
		tab_dirs = print_list_fl_rec(list_dir_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_frt(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_no_flags(parms);
		tab_dirs = print_list_fr_rec(list_dir_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fa(parms);
		tab_dirs = print_list_fr_rec(list_dir_fat(parms), parms);
	}
	return (tab_dirs);
}
