/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 05:00:15 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:58:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	scan_dirlnk_fal(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	if (!parms.cur_dir.error)
		parms = init_info_for_padding(parms);
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
		if (stat(path_ent, &parms.cur_dir.infent) != -1)
		{
			parms = get_info_for_padding(parms, 0, type_obj(parms));
			if (type_obj(parms) == 'd')
				parms.cur_dir.cdirs++;
			parms.cur_dir.cobjs++;
		}
		free(path_ent);
	}
	return (parms);
}

t_parms	scan_dirlnk_fl(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	if (!parms.cur_dir.error)
		parms = init_info_for_padding(parms);
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		if (!is_shadow(ent->d_name))
		{
			path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
			if (stat(path_ent, &parms.cur_dir.infent) != -1)
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

t_parms	scan_dirlnk_fa(t_parms parms)
{
	struct dirent	*ent;
	char			*path_ent;

	parms.cur_dir.cdirs = 0;
	parms.cur_dir.cobjs = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
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
	return (parms);
}
