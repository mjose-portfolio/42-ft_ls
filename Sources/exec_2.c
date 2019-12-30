/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:27:22 by mjose             #+#    #+#             */
/*   Updated: 2018/08/02 18:52:45 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_one_obj_fr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fr(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_fr(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_fat(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_ft(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_fat(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}

void	exec_one_obj_falt(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_flt(parms);
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

void	exec_one_obj_flt(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_flt(parms);
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

void	exec_one_obj_ft(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_ft(parms);
		else if (parms.cur_dir.type == 'l')
			parms = exec_one_lnk_ft(parms);
		else
			display_file_def(parms);
	}
	free(parms.to_list[0]);
	free(parms.to_list);
}
