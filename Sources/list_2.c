/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 05:26:57 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 00:00:23 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**list_dirlnk_fat(t_parms parms)
{
	struct dirent	*ent;
	char			**entrys;
	int				l;
	char			*path_ent;

	parms = open_new_dir(parms);
	entrys = crt_tab_void(parms.cur_dir.cobjs + 1);
	l = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
		if (lstat(path_ent, &parms.cur_dir.infent) != -1)
		{
			entrys[l] = ft_strdup(ent->d_name);
			l++;
			entrys[l] = NULL;
		}
		free(path_ent);
	}
	entrys[l] = NULL;
	closedir(parms.cur_dir.opdir);
	sort_alph(entrys, parms.cur_dir.cobjs);
	return (return_for_list_ft(parms, entrys));
}

char	**list_dirlnk_ft(t_parms parms)
{
	struct dirent	*ent;
	char			**entrys;
	int				l;
	char			*path_ent;

	parms = open_new_dir(parms);
	entrys = crt_tab_void(parms.cur_dir.cobjs + 1);
	l = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		if ((!is_shadow(ent->d_name) && !parms.flags.ga) ||
			(!is_system(ent->d_name) && parms.flags.ga))
		{
			path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
			if (lstat(path_ent, &parms.cur_dir.infent) != -1)
				entrys[l++] = ft_strdup(ent->d_name);
			free(path_ent);
		}
	}
	entrys[l] = NULL;
	closedir(parms.cur_dir.opdir);
	sort_alph(entrys, parms.cur_dir.cobjs);
	return (return_for_list_ft(parms, entrys));
}

char	**list_dirlnk_fa(t_parms parms)
{
	struct dirent	*ent;
	char			**entrys;
	int				l;
	char			*path_ent;

	closedir(parms.cur_dir.opdir);
	parms.cur_dir.opdir = opendir(parms.cur_dir.path_dir);
	entrys = crt_tab_void(parms.cur_dir.cobjs + 1);
	l = 0;
	while ((ent = readdir(parms.cur_dir.opdir)) != NULL)
	{
		path_ent = path_it(parms.cur_dir.path_obj, ent->d_name);
		if (lstat(path_ent, &parms.cur_dir.infent) != -1)
		{
			entrys[l] = ft_strdup(ent->d_name);
			l++;
			entrys[l] = NULL;
		}
		free(path_ent);
	}
	entrys[l] = NULL;
	closedir(parms.cur_dir.opdir);
	return (sort_alph(entrys, parms.cur_dir.cobjs));
}
