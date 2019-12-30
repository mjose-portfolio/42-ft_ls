/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:00:02 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 20:29:38 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_cur_dir_time_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_ft(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_ft(tab_dirs[l], parms);
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

void	exec_rec_def(char *dir, t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	put_desc(dir);
	if (!parms.cur_dir.error)
	{
		parms = init_dir(dir, parms);
		tab_dirs = display_dir_for_rec_def(parms);
	}
	if (!parms.cur_dir.error && tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_def(tab_dirs[l], parms);
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

void	exec_cur_dir_def_rec(t_parms parms)
{
	char	**tab_dirs;
	int		l;

	l = 0;
	tab_dirs = NULL;
	parms = init_dir(".", parms);
	tab_dirs = display_dir_for_rec_def(parms);
	if (tab_dirs)
	{
		while (tab_dirs[l])
		{
			exec_rec_def(tab_dirs[l], parms);
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

void	exec_cur_dir_rec(t_parms parms)
{
	if (!parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_cur_dir_def_rec(parms);
	else if (!parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_cur_dir_time_def_rec(parms);
	else if (!parms.flags.l && !parms.flags.t && parms.flags.pr)
		exec_cur_dir_fr_rec(parms);
	else if (parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_cur_dir_long_def_rec(parms);
	else if (!parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_cur_dir_frt_rec(parms);
	else if (parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_cur_dir_time_long_rec(parms);
	else if (parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_cur_dir_time_long_rev_rec(parms);
	else if (parms.flags.l && !parms.flags.t && parms.flags.pr)
		exec_cur_dir_long_rev_rec(parms);
}

void	exec_one_fa(t_parms parms)
{
	if (!parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_one_obj_fa(parms);
	else if (parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_one_obj_fal(parms);
	else if (!parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_one_obj_fat(parms);
	else if (parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_one_obj_falt(parms);
	else if (!parms.flags.l && !parms.flags.t && parms.flags.pr)
		exec_one_obj_far(parms);
	else if (parms.flags.l && !parms.flags.t && parms.flags.pr)
		exec_one_obj_falr(parms);
	else if (!parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_one_obj_fatr(parms);
	else if (parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_one_obj_faltr(parms);
}
