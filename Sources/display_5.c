/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 06:56:36 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 21:27:52 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**display_dirlnk_for_rec_fltr(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_fl(parms);
		tab_dirs = print_list_lnk_flr_rec(list_dirlnk_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_flr_rec(list_dirlnk_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dirlnk_for_rec_flt(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_fl(parms);
		tab_dirs = print_list_lnk_fl_rec(list_dirlnk_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fal(parms);
		tab_dirs = print_list_lnk_fl_rec(list_dirlnk_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dirlnk_for_rec_frt(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_no_flags(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dirlnk_for_rec_fl(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_no_flags(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_fa(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dirlnk_for_rec_fr(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dirlnk_no_flags(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dirlnk_fa(parms);
		tab_dirs = print_list_lnk_fr_rec(list_dirlnk_fa(parms), parms);
	}
	return (tab_dirs);
}
