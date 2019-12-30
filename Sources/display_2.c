/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:45:32 by mjose             #+#    #+#             */
/*   Updated: 2018/08/02 19:39:58 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	display_dir_ftr(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_no_flags(parms);
		print_list_fr(list_dir_ft(parms), parms);
	}
	else
	{
		parms = scan_dir_fa(parms);
		print_list_fr(list_dir_fat(parms), parms);
	}
}

void	display_dir_flr(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_fl(parms);
		print_list_flr(list_dir_no_flags(parms), parms);
	}
	else
	{
		parms = scan_dir_fal(parms);
		print_list_flr(list_dir_fa(parms), parms);
	}
}

void	display_dir_fr(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_no_flags(parms);
		print_list_fr(list_dir_no_flags(parms), parms);
	}
	else
	{
		parms = scan_dir_fa(parms);
		print_list_fr(list_dir_fa(parms), parms);
	}
}

void	display_dir_flt(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_fl(parms);
		print_list_fl(list_dir_ft(parms), parms);
	}
	else
	{
		parms = scan_dir_fal(parms);
		print_list_fl(list_dir_fat(parms), parms);
	}
}

void	display_dir_ft(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_no_flags(parms);
		print_list(list_dir_ft(parms), parms);
	}
	else
	{
		parms = scan_dir_fa(parms);
		print_list(list_dir_fat(parms), parms);
	}
}
