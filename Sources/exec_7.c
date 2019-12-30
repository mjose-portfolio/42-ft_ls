/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:15:13 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:31:02 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	exec_one_lnk_fa(t_parms parms)
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

t_parms	exec_one_lnk_ftr(t_parms parms)
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

t_parms	exec_one_lnk_fatr(t_parms parms)
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

t_parms	exec_one_lnk_ft(t_parms parms)
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

t_parms	exec_one_lnk_fat(t_parms parms)
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
