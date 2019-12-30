/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:57:48 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 20:10:10 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_obj_fa(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_def(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_fa(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_fal(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fl(parms);
		else if (parms.cur_dir.type == 'l' &&
			parms.cur_dir.path_obj[ft_strlen(parms.cur_dir.path_obj)] != '/')
			display_link_fl(parms);
		else if (parms.cur_dir.type == 'l' &&
			parms.cur_dir.path_obj[ft_strlen(parms.cur_dir.path_obj)] == '/')
			parms = exec_one_lnk_fa(parms);
		else
			display_file_fl(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_fl(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fl(parms);
		else if (parms.cur_dir.type == 'l' &&
			parms.cur_dir.path_obj[ft_strlen(parms.cur_dir.path_obj)] != '/')
			display_link_fl(parms);
		else if (parms.cur_dir.type == 'l' &&
			parms.cur_dir.path_obj[ft_strlen(parms.cur_dir.path_obj)] == '/')
			parms = exec_one_lnk(parms);
		else
			display_file_fl(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_def(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec(t_parms parms)
{
	if (!parms.obj_to_list && !parms.flags.l &&
			!parms.flags.t && !parms.flags.pr && !parms.flags.gr)
		exec_cur_dir_def(parms);
	else if (!parms.obj_to_list && !parms.flags.l &&
				parms.flags.t && !parms.flags.pr && !parms.flags.gr)
		exec_cur_dir_time_def(parms);
	else if (!parms.obj_to_list && !parms.flags.l &&
				!parms.flags.t && parms.flags.pr && !parms.flags.gr)
		exec_cur_dir_rev(parms);
	else if (!parms.obj_to_list && !parms.flags.l &&
				parms.flags.t && parms.flags.pr && !parms.flags.gr)
		exec_cur_dir_time_rev(parms);
	else if (!parms.obj_to_list && parms.flags.l && !parms.flags.gr)
		exec_long(parms);
	else if (!parms.obj_to_list && parms.flags.gr)
		exec_cur_dir_rec(parms);
	else if (parms.obj_to_list == 1 && parms.flags.gr)
		exec_one_rec(parms);
	else if (parms.obj_to_list == 1 && !parms.flags.gr)
		exec_one(parms);
	else if (parms.obj_to_list > 1)
		exec_var(parms);
}
