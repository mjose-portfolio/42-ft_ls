/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:05:55 by mjose             #+#    #+#             */
/*   Updated: 2018/08/02 19:37:50 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_obj_fatr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_ftr(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_fatr(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_ftr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_ftr(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_ftr(parms);
		else
			clear_dir_error(parms.cur_dir);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_falr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_flr(parms);
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

void	exec_one_obj_flr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_flr(parms);
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

void	exec_one_obj_far(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fr(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_far(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}
