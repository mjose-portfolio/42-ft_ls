/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:05:54 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 20:08:37 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	display_file_fl(t_parms parms)
{
	parms = init_info_for_padding(parms);
	scan_obj_fl(parms);
	closedir(parms.cur_dir.opdir);
	clear_dir_error(parms.cur_dir);
}

void	display_link_fl(t_parms parms)
{
	scan_obj_fl(parms);
	closedir(parms.cur_dir.opdir);
	clear_dir_error(parms.cur_dir);
}

void	display_dir_fl(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_fl(parms);
		print_list_fl(list_dir_no_flags(parms), parms);
	}
	else
	{
		parms = scan_dir_fal(parms);
		print_list_fl(list_dir_fa(parms), parms);
	}
}

void	display_file_def(t_parms parms)
{
	scan_obj_no_flags(parms);
	clear_dir_error(parms.cur_dir);
}

void	display_dir_def(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = scan_dir_no_flags(parms);
		print_list(list_dir_no_flags(parms), parms);
	}
	else
	{
		parms = scan_dir_fa(parms);
		print_list(list_dir_fa(parms), parms);
	}
}
