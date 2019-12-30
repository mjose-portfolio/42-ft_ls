/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:17:13 by mjose             #+#    #+#             */
/*   Updated: 2018/08/04 07:30:27 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_fl_rec(char *dir, t_parms parms, int first)
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
		tab_dirs = display_dir_for_rec_fl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
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

void	exec_one_dirlnk_rev_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_fr(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_rev(tab_dirs[l], parms);
			parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_fr_rec(char *dir, t_parms parms, int first)
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
		tab_dirs = display_dir_for_rec_fr(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l]);
			l++;
		}
		free(tab_dirs);
	}
}

void	exec_one_dirlnk_time_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_ft(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_ft(tab_dirs[l], parms);
			parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_ft_rec(char *dir, t_parms parms, int first)
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
		tab_dirs = display_dir_for_rec_ft(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_ft(tab_dirs[l], parms);
			parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}
