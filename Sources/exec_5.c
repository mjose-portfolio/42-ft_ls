/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 02:11:59 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:28:45 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_cur_dir_time_rev(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_no_flags(parms);
		print_list_fr(list_dir_ft(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fa(parms);
		print_list_fr(list_dir_fat(parms), parms);
	}
}

void	exec_cur_dir_long_rev(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fl(parms);
		print_list_flr(list_dir_no_flags(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fal(parms);
		print_list_flr(list_dir_fa(parms), parms);
	}
}

void	exec_cur_dir_rev(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_no_flags(parms);
		print_list_fr(list_dir_no_flags(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fa(parms);
		print_list_fr(list_dir_fa(parms), parms);
	}
}

void	exec_cur_dir_time_long(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fl(parms);
		print_list_fl(list_dir_ft(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fal(parms);
		print_list_fl(list_dir_fat(parms), parms);
	}
}

void	exec_cur_dir_time_def(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_no_flags(parms);
		print_list(list_dir_ft(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fa(parms);
		print_list(list_dir_fat(parms), parms);
	}
}
