/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:34:27 by mjose             #+#    #+#             */
/*   Updated: 2018/08/04 03:22:22 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_cur_dir_time_long_rev_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_frtl(parms);
	if (tab_dirs)
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

void	exec_rec_time_long(char *dir, t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	put_desc(dir);
	if (!parms.cur_dir.error)
	{
		parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_ftl(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
				parms.cur_dir.error = 0;
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_cur_dir_time_long_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_ftl(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_long(tab_dirs[l], parms);
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

void	exec_rec_time_rev(char *dir, t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	put_desc(dir);
	if (!parms.cur_dir.error)
	{
		parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_frt(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_rev(tab_dirs[l], parms);
			if (parms.cur_dir.error != 0)
			{
				parms.cur_dir.error = 0;
			}
			free(tab_dirs[l++]);
		}
		free(tab_dirs);
	}
}

void	exec_cur_dir_frt_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_frt(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_time_rev(tab_dirs[l], parms);
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
