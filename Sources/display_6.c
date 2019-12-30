/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:54:47 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 21:27:28 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**display_dir_for_rec_frl(t_parms parms)
{
	char	**tab_dirs;

	tab_dirs = NULL;
	if (!parms.flags.a && !parms.cur_dir.error)
	{
		parms = scan_dir_fl(parms);
		tab_dirs = print_list_flr_rec(list_dir_no_flags(parms), parms);
	}
	else if (!parms.cur_dir.error)
	{
		parms = scan_dir_fal(parms);
		tab_dirs = print_list_flr_rec(list_dir_fa(parms), parms);
	}
	return (tab_dirs);
}
