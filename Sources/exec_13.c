/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:42:34 by mjose             #+#    #+#             */
/*   Updated: 2018/08/04 08:18:09 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_dirlnk_flt_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_flt(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l]);
			l++;
		}
		free(tab_dirs);
	}
}

void	exec_one_flt_rec(char *dir, t_parms parms, int first)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	if (!first)
		put_desc(dir);
	if (!parms.cur_dir.error)
	{
		if (!first)
			parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_ftl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_dirlnk_frt_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_frt(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_frt_rec(char *dir, t_parms parms, int first)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	if (!first)
		put_desc(dir);
	if (!parms.cur_dir.error)
	{
		if (!first)
			parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_frt(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_dirlnk_long_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_fl(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_long(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}
