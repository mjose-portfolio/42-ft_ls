/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:40:19 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:39:56 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	init_path_lnk(char *path, t_parms parms)
{
	int		l;
	char	*tmp;

	parms.cur_dir.path_dir = rmv_obj_frm_path(path);
	parms.cur_dir.path_obj = ft_strdup(path);
	parms.cur_dir.obj = rmv_path_frm_obj(path);
	l = readlink(path, parms.cur_dir.path_lnk, 1023);
	parms.cur_dir.path_lnk[l] = '\0';
	if (parms.cur_dir.path_lnk[0] != '/')
	{
		tmp = ft_strjoin(parms.cur_dir.path_dir, parms.cur_dir.path_lnk);
		ft_memcpy(parms.cur_dir.path_lnk, tmp, ft_strlen(tmp));
		free(tmp);
	}
	return (parms);
}

t_parms	init_path_obj(char *path, t_parms parms)
{
	parms.cur_dir.path_dir = rmv_obj_frm_path(path);
	parms.cur_dir.path_obj = ft_strdup(path);
	parms.cur_dir.obj = rmv_path_frm_obj(path);
	parms.cur_dir.path_lnk[0] = '\0';
	return (parms);
}

t_parms	init_path_dir(char *path, t_parms parms)
{
	parms.cur_dir.path_dir = ft_strdup(path);
	parms.cur_dir.path_obj = ft_strdup(path);
	parms.cur_dir.obj = rmv_path_frm_obj(path);
	parms.cur_dir.path_lnk[0] = '\0';
	return (parms);
}

t_parms	init_path(char *obj, t_parms parms)
{
	char *path;

	path = check_path_obj(obj);
	if (lstat(path, &parms.cur_dir.inf) == -1)
	{
		parms.cur_dir.error = 1;
		parms.cur_dir.type = '\0';
	}
	else
	{
		parms.cur_dir.type = type_parm(parms);
		parms = check_init_path(path, obj, parms);
		free(path);
		return (parms);
	}
	parms.cur_dir.error = 1;
	free(path);
	return (parms);
}

t_parms	init_dir(char *obj, t_parms parms)
{
	parms = init_path(obj, parms);
	if (parms.cur_dir.error || parms.cur_dir.type == 'n')
	{
		parms = open_dir(obj, parms);
		return (parms);
	}
	parms = open_dir(parms.cur_dir.path_dir, parms);
	return (parms);
}
