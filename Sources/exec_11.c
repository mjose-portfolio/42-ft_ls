/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:21:09 by mjose             #+#    #+#             */
/*   Updated: 2018/08/04 04:03:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_dirlnk_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = display_dirlnk_for_rec_def(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_def(tab_dirs[l], parms);
			parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_lnk_rec(t_parms parms)
{
	stat(parms.cur_dir.path_obj, &parms.cur_dir.inflnk);
	if (type_lnk(parms) == 'd')
	{
		closedir(parms.cur_dir.opdir);
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_obj);
		free(parms.cur_dir.path_dir);
		parms.cur_dir.path_dir = ft_strdup(parms.cur_dir.path_obj);
		if (!parms.flags.l && !parms.flags.t && !parms.flags.pr)
			exec_one_dirlnk_def_rec(parms);
		else if (!parms.flags.l && parms.flags.t && !parms.flags.pr)
			exec_one_dirlnk_time_def_rec(parms);
		else if (!parms.flags.l && !parms.flags.t && parms.flags.pr)
			exec_one_dirlnk_rev_def_rec(parms);
		else if (parms.flags.l && !parms.flags.t && !parms.flags.pr)
			exec_one_dirlnk_long_def_rec(parms);
		else if (!parms.flags.l && parms.flags.t && parms.flags.pr)
			exec_one_dirlnk_frt_rec(parms);
		else if (parms.flags.l && parms.flags.t && !parms.flags.pr)
			exec_one_dirlnk_flt_rec(parms);
		else if (parms.flags.l && parms.flags.t && parms.flags.pr)
			exec_one_dirlnk_fltr_rec(parms);
	}
}

void	exec_one_def_rec(char *dir, t_parms parms, int first)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	if (!first)
		put_desc(dir);
	if (!parms.cur_dir.error)
	{
		if (!first)
			parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_def(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_def(tab_dirs[l], parms);
			parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_rec(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (parms.cur_dir.type == 'd')
	{
		exec_one_dir(parms);
		free(parms.to_list[0]);
		free(parms.to_list);
	}
	else if (parms.cur_dir.type == '-' ||
		(parms.cur_dir.type == 'l' &&
		parms.to_list[0][ft_strlen(parms.to_list[0])] != '/' &&
		parms.flags.l))
	{
		exec_one(parms);
		closedir(parms.cur_dir.opdir);
		clear_dir_error(parms.cur_dir);
	}
	else if (parms.cur_dir.type == 'l')
	{
		exec_one_lnk_rec(parms);
		free(parms.to_list[0]);
		free(parms.to_list);
	}
}

void	exec_rec_time_long_rev(char *dir, t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	put_desc(dir);
	if (!parms.cur_dir.error)
	{
		parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_frtl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
			{
				clear_dir_error(parms.cur_dir);
				parms.cur_dir.error = 0;
			}
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}
