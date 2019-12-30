/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 01:04:14 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 20:08:18 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_rec_long_rev(char *dir, t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	put_desc(dir);
	if (!parms.cur_dir.error)
	{
		parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_frl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_long_rev(tab_dirs[l], parms);
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

void	exec_cur_dir_long_rev_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_frl(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_long_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
			{
				clear_dir_error(parms.cur_dir);
				parms.cur_dir.error = 0;
			}
			free(tab_dirs[l]);
			l++;
		}
		free(tab_dirs);
	}
}

void	exec_var(t_parms parms)
{
	sort_alph(parms.to_list, parms.obj_to_list);
	if (check_for_fts(parms))
		return ;
	parms = fill_var_tab(parms);
	exec_var_run(parms, parms.var.j, parms.var.y);
}

void	exec_one_dirlnk_fltr_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	tab_dirs = display_dirlnk_for_rec_fltr(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_one_fltr_rec(char *dir, t_parms parms, int first)
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
		tab_dirs = display_dir_for_rec_frtl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir = reset_dir_error(parms.cur_dir);
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}
