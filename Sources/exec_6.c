/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:51:25 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:29:39 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	exec_one_lnk_far(t_parms parms)
{
	char			*tmpdir;

	stat(parms.cur_dir.path_obj, &parms.cur_dir.inflnk);
	if (type_lnk(parms) == 'd')
	{
		closedir(parms.cur_dir.opdir);
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_obj);
		scan_print_dirlnk_fa(parms);
	}
	else
	{
		tmpdir = ft_strdup(parms.cur_dir.path_obj);
		clear_dir(parms.cur_dir);
		closedir(parms.cur_dir.opdir);
		parms = init_dir(tmpdir, parms);
		parms = scan_obj_no_flags(parms);
		free(tmpdir);
	}
	return (parms);
}

t_parms	exec_one_lnk_fr(t_parms parms)
{
	char			*tmpdir;

	stat(parms.cur_dir.path_obj, &parms.cur_dir.inflnk);
	if (type_lnk(parms) == 'd')
	{
		closedir(parms.cur_dir.opdir);
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_obj);
		scan_print_dirlnk(parms);
	}
	else
	{
		tmpdir = ft_strdup(parms.cur_dir.path_obj);
		clear_dir(parms.cur_dir);
		closedir(parms.cur_dir.opdir);
		parms = init_dir(tmpdir, parms);
		parms = scan_obj_no_flags(parms);
		free(tmpdir);
	}
	return (parms);
}

void	exec_one(t_parms parms)
{
	if (!parms.flags.a)
	{
		if (!parms.flags.l && !parms.flags.t && !parms.flags.pr)
			exec_one_obj(parms);
		else if (parms.flags.l && !parms.flags.t && !parms.flags.pr)
			exec_one_obj_fl(parms);
		else if (!parms.flags.l && parms.flags.t && !parms.flags.pr)
			exec_one_obj_ft(parms);
		else if (parms.flags.l && parms.flags.t && !parms.flags.pr)
			exec_one_obj_flt(parms);
		else if (!parms.flags.l && !parms.flags.t && parms.flags.pr)
			exec_one_obj_fr(parms);
		else if (parms.flags.l && !parms.flags.t && parms.flags.pr)
			exec_one_obj_flr(parms);
		else if (!parms.flags.l && parms.flags.t && parms.flags.pr)
			exec_one_obj_ftr(parms);
		else if (parms.flags.l && parms.flags.t && parms.flags.pr)
			exec_one_obj_fltr(parms);
	}
	else
		exec_one_fa(parms);
}

void	exec_long(t_parms parms)
{
	if (!parms.obj_to_list && parms.flags.l &&
				!parms.flags.t && !parms.flags.pr)
		exec_cur_dir_long_def(parms);
	else if (!parms.obj_to_list && parms.flags.l &&
				parms.flags.t && !parms.flags.pr)
		exec_cur_dir_time_long(parms);
	else if (!parms.obj_to_list && parms.flags.l &&
				!parms.flags.t && parms.flags.pr)
		exec_cur_dir_long_rev(parms);
	else if (!parms.obj_to_list && parms.flags.l &&
				parms.flags.t && parms.flags.pr)
		exec_cur_dir_time_long_rev(parms);
}

void	exec_cur_dir_time_long_rev(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fl(parms);
		print_list_flr(list_dir_ft(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fal(parms);
		print_list_flr(list_dir_fat(parms), parms);
	}
}
