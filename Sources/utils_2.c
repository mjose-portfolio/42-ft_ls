/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 00:57:52 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 19:14:06 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	tab_it(t_parms parms, int i, int j)
{
	if (type_obj(parms) != 'd')
	{
		parms.files[i] = ft_strdup(parms.to_list[j]);
		parms.var.have_files = 1;
	}
	else
	{
		parms.dirs[i] = ft_strdup(parms.to_list[j]);
		parms.var.have_dirs = 1;
	}
	return (parms);
}

t_parms	init_var_parms(t_parms parms)
{
	parms.var.have_dirs = 0;
	parms.var.have_files = 0;
	parms.files =
		(char **)malloc(sizeof(char *) * (parms.obj_to_list + 1));
	parms.dirs =
		(char **)malloc(sizeof(char *) * (parms.obj_to_list + 1));
	parms.var.i = 0;
	parms.var.j = 0;
	parms.var.y = 0;
	return (parms);
}

void	clear_current_parm(t_parms parms, char *path_ent)
{
	closedir(parms.cur_dir.opdir);
	clear_dir_error(parms.cur_dir);
	free(path_ent);
}

t_parms	fill_var_tab_by_type(t_parms parms)
{
	char	*path_ent;

	if (!parms.cur_dir.error &&
		ft_strcmp(parms.to_list[parms.var.i], "fts_open"))
	{
		path_ent = path_it(parms.cur_dir.path_dir, parms.to_list[parms.var.i]);
		if (parms.cur_dir.type == '-' || parms.cur_dir.type == 'l')
		{
			if (stat(path_ent, &parms.cur_dir.infent) != -1)
			{
				if (type_obj(parms) != 'd')
					parms = tab_it(parms, parms.var.j++, parms.var.i);
				else
					parms = tab_it(parms, parms.var.y++, parms.var.i);
			}
		}
		else if (ft_strcmp(parms.to_list[parms.var.i], "fts_open"))
		{
			parms.dirs[parms.var.y++] = ft_strdup(parms.to_list[parms.var.i]);
			parms.var.have_dirs = 1;
		}
		clear_current_parm(parms, path_ent);
	}
	return (parms);
}

t_parms	fill_var_tab(t_parms parms)
{
	parms = init_var_parms(parms);
	while (parms.to_list[parms.var.i])
	{
		parms = init_dir(parms.to_list[parms.var.i], parms);
		parms = fill_var_tab_by_type(parms);
		free(parms.to_list[parms.var.i++]);
		parms.files[parms.var.j] = NULL;
		parms.dirs[parms.var.y] = NULL;
	}
	return (parms);
}
