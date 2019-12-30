/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:24:12 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:56:24 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	scan_obj_no_flags(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
		if (!ft_strcmp(ent->d_name, parms.cur_dir.obj))
		{
			path_ent = path_it(parms.cur_dir.path_dir, parms.to_list[0]);
			lstat(parms.to_list[0], &parms.cur_dir.infent);
			if (type_obj(parms) == 'l')
			{
				stat(path_ent, &parms.cur_dir.infent);
				parms = scan_lnk(parms);
			}
			else
				ft_putendl(parms.to_list[0]);
			free(path_ent);
		}
	closedir(parms.cur_dir.opdir);
	return (parms);
}

t_parms	scan_dir_fa(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		path_ent = path_it(parms.cur_dir.path_dir, ent->d_name);
		if (lstat(path_ent, &parms.cur_dir.infent) != -1)
		{
			if (type_obj(parms) == 'd' && !is_system(ent->d_name))
				parms.cur_dir.cdirs++;
			parms.cur_dir.cobjs++;
		}
		free(path_ent);
	}
	return (parms);
}

t_parms	scan_dir_fal(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	parms = init_info_for_padding(parms);
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		path_ent = path_it(parms.cur_dir.path_dir, ent->d_name);
		if (lstat(path_ent, &parms.cur_dir.infent) != -1)
		{
			parms = get_info_for_padding(parms, 0, type_obj(parms));
			if (type_obj(parms) == 'd' && !is_system(ent->d_name))
				parms.cur_dir.cdirs++;
			parms.cur_dir.cobjs++;
		}
		free(path_ent);
	}
	return (parms);
}

t_parms	scan_dir_fl(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	if (!parms.cur_dir.error)
		parms = init_info_for_padding(parms);
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		if ((!is_shadow(ent->d_name) && !parms.flags.ga) ||
			(!is_system(ent->d_name) && parms.flags.ga))
		{
			path_ent = path_it(parms.cur_dir.path_dir, ent->d_name);
			if (lstat(path_ent, &parms.cur_dir.infent) != -1)
			{
				parms = get_info_for_padding(parms, 0, type_obj(parms));
				if (type_obj(parms) == 'd')
					parms.cur_dir.cdirs++;
				parms.cur_dir.cobjs++;
			}
			free(path_ent);
		}
	}
	return (parms);
}

t_parms	scan_dir_no_flags(t_parms parms)
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
			path_ent = path_it(parms.cur_dir.path_dir, ent->d_name);
			if (lstat(path_ent, &parms.cur_dir.infent) != -1)
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
