/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:50:18 by mjose             #+#    #+#             */
/*   Updated: 2018/08/02 19:54:44 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_cur_dir_long_def(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fl(parms);
		print_list_fl(list_dir_no_flags(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fal(parms);
		print_list_fl(list_dir_fa(parms), parms);
	}
}

void	exec_cur_dir_def(t_parms parms)
{
	if (!parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_no_flags(parms);
		print_list(list_dir_no_flags(parms), parms);
	}
	else if (parms.flags.a)
	{
		parms = init_dir(".", parms);
		parms = scan_dir_fa(parms);
		print_list(list_dir_fa(parms), parms);
	}
}

t_parms	exec_one_lnk(t_parms parms)
{
	char	*tmpdir;

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
		clear_dir_error(parms.cur_dir);
		closedir(parms.cur_dir.opdir);
		parms = init_dir(tmpdir, parms);
		parms = scan_obj_no_flags(parms);
		clear_dir_error(parms.cur_dir);
		free(tmpdir);
	}
	return (parms);
}

void	exec_one_obj_faltr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fltr(parms);
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

void	exec_one_obj_fltr(t_parms parms)
{
	parms = init_dir(parms.to_list[0], parms);
	if (!parms.cur_dir.error)
	{
		if (parms.cur_dir.type == 'd')
			display_dir_fltr(parms);
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
