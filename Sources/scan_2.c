/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:50:35 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:57:28 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	scan_dirlnk_no_flags(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		if ((!is_shadow(ent->d_name) && !parms.flags.ga) ||
			(!is_system(ent->d_name) && parms.flags.ga))
		{
			path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
			if (stat(path_ent, &parms.cur_dir.infent) != -1)
			{
				if (type_obj(parms) == 'd')
					parms.cur_dir.cdirs++;
				parms.cur_dir.cobjs++;
			}
			free(path_ent);
		}
	}
	return (parms);
}

t_parms	scan_lnk(t_parms parms)
{
	if (type_obj(parms) == 'd')
	{
		closedir(parms.cur_dir.opdir);
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_obj);
		if (parms.flags.a)
			scan_print_dirlnk_fa(parms);
		else
			scan_print_dirlnk(parms);
	}
	else
		put_link_obj(parms.to_list[0], parms);
	return (parms);
}

void	scan_print_dirlnk(t_parms parms)
{
	parms = scan_dirlnk_no_flags(parms);
	if (parms.flags.pr && !parms.flags.t)
		print_list_lnk_fr(list_dirlnk_no_flags(parms), parms);
	else if (!parms.flags.pr && parms.flags.t)
		print_list_lnk(list_dirlnk_ft(parms), parms);
	else if (parms.flags.pr && parms.flags.t)
		print_list_lnk_fr(list_dirlnk_ft(parms), parms);
	else
		print_list_lnk(list_dirlnk_no_flags(parms), parms);
}

void	scan_print_dirlnk_fa(t_parms parms)
{
	parms = scan_dirlnk_fa(parms);
	if (parms.flags.pr && !parms.flags.t)
		print_list_lnk_fr(list_dirlnk_fa(parms), parms);
	else if (!parms.flags.pr && parms.flags.t)
		print_list_lnk(list_dirlnk_fat(parms), parms);
	else if (parms.flags.pr && parms.flags.t)
		print_list_lnk_fr(list_dirlnk_fat(parms), parms);
	else
		print_list_lnk(list_dirlnk_fa(parms), parms);
}

t_parms	scan_obj_fl(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	parms = init_info_for_padding(parms);
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		if (!ft_strcmp(ent->d_name, parms.cur_dir.obj))
		{
			path_ent = path_it(parms.cur_dir.path_dir, ent->d_name);
			lstat(path_ent, &parms.cur_dir.infent);
			parms = get_info_for_padding(parms, 1, type_obj(parms));
			apply_long(parms, path_ent);
			if (type_obj(parms) == 'l')
				put_link(parms.to_list[0], path_ent, parms);
			else
				ft_putendl(parms.to_list[0]);
			free(path_ent);
		}
	}
	return (parms);
}
