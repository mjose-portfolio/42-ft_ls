/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:04:18 by mjose             #+#    #+#             */
/*   Updated: 2018/07/16 01:34:04 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	type_parm(t_parms parms)
{
	if (S_ISDIR(parms.cur_dir.inf.st_mode))
		return ('d');
	else if (S_ISREG(parms.cur_dir.inf.st_mode))
		return ('-');
	else if (S_ISLNK(parms.cur_dir.inf.st_mode))
		return ('l');
	else if (S_ISBLK(parms.cur_dir.inf.st_mode))
		return ('b');
	else if (S_ISCHR(parms.cur_dir.inf.st_mode))
		return ('c');
	else if (S_ISSOCK(parms.cur_dir.inf.st_mode))
		return ('s');
	else if (S_ISFIFO(parms.cur_dir.inf.st_mode))
		return ('p');
	else
		return ('n');
}

char	type_obj(t_parms parms)
{
	if (S_ISDIR(parms.cur_dir.infent.st_mode))
		return ('d');
	else if (S_ISREG(parms.cur_dir.infent.st_mode))
		return ('-');
	else if (S_ISLNK(parms.cur_dir.infent.st_mode))
		return ('l');
	else if (S_ISBLK(parms.cur_dir.infent.st_mode))
		return ('b');
	else if (S_ISCHR(parms.cur_dir.infent.st_mode))
		return ('c');
	else if (S_ISSOCK(parms.cur_dir.infent.st_mode))
		return ('s');
	else if (S_ISFIFO(parms.cur_dir.infent.st_mode))
		return ('p');
	else
		return ('n');
}

char	type_lnk(t_parms parms)
{
	if (S_ISDIR(parms.cur_dir.inflnk.st_mode))
		return ('d');
	else if (S_ISREG(parms.cur_dir.inflnk.st_mode))
		return ('-');
	else if (S_ISLNK(parms.cur_dir.inflnk.st_mode))
		return ('l');
	else if (S_ISBLK(parms.cur_dir.inflnk.st_mode))
		return ('b');
	else if (S_ISCHR(parms.cur_dir.inflnk.st_mode))
		return ('c');
	else if (S_ISSOCK(parms.cur_dir.inflnk.st_mode))
		return ('s');
	else if (S_ISFIFO(parms.cur_dir.inflnk.st_mode))
		return ('p');
	else
		return ('n');
}

int		is_system(char *obj)
{
	if (obj && (!ft_strcmp(obj, ".") || !ft_strcmp(obj, "..")))
		return (1);
	else
		return (0);
}

int		is_shadow(char *obj)
{
	if (obj && (is_system(obj) || obj[0] == '.'))
		return (1);
	else
		return (0);
}
