/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:44:18 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 21:28:37 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**display_dir_for_rec_fl(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_fl(parms);
		tab_dirs = print_list_fl_rec(list_dir_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fal(parms);
		tab_dirs = print_list_fl_rec(list_dir_fa(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_fr(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_no_flags(parms);
		tab_dirs = print_list_fr_rec(list_dir_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fa(parms);
		tab_dirs = print_list_fr_rec(list_dir_fa(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_ft(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_no_flags(parms);
		tab_dirs = print_list_rec(list_dir_ft(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fa(parms);
		tab_dirs = print_list_rec(list_dir_fat(parms), parms);
	}
	return (tab_dirs);
}

char	**display_dir_for_rec_def(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_no_flags(parms);
		tab_dirs = print_list_rec(list_dir_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fa(parms);
		tab_dirs = print_list_rec(list_dir_fa(parms), parms);
	}
	return (tab_dirs);
}

void	display_dir_fltr(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_fl(parms);
		print_list_flr(list_dir_ft(parms), parms);
	}
	else
	{
		parms = scan_dir_fal(parms);
		print_list_flr(list_dir_fat(parms), parms);
	}
}
