/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:27:26 by mjose             #+#    #+#             */
/*   Updated: 2018/08/09 20:54:50 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	open_new_dir(t_parms parms)
{
	closedir(parms.cur_dir.opdir);
	if (parms.cur_dir.type == 'l')
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_obj);
	else
		parms.cur_dir.opdir = opendir(parms.cur_dir.path_dir);
	return (parms);
}

void	close_dir(t_parms parms)
{
	closedir(parms.cur_dir.opdir);
	if (parms.cur_dir.path_dir)
		free(parms.cur_dir.path_dir);
	if (parms.cur_dir.path_obj)
		free(parms.cur_dir.path_obj);
	if (parms.cur_dir.obj)
		free(parms.cur_dir.obj);
}

t_parms	open_dir(char *obj, t_parms parms)
{
	parms.cur_dir.opdir = opendir(obj);
	if (parms.cur_dir.opdir == NULL && parms.cur_dir.type != 'l')
	{
		print_error_open(obj, parms);
		if (!parms.cur_dir.error)
			clear_dir_error(parms.cur_dir);
		parms.cur_dir.error = 1;
	}
	return (parms);
}
