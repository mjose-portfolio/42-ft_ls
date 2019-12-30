/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:22:03 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 21:06:23 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms		get_info_for_padding_var(t_parms parms, int i)
{
	char	*path_ent;

	if (parms.flags.l)
	{
		parms = init_dir(parms.files[i], parms);
		path_ent = path_it(parms.cur_dir.path_dir, parms.files[i]);
		if (lstat(path_ent, &parms.cur_dir.infent) != -1)
			parms = get_info_for_padding(parms, 1, '-');
		free(path_ent);
		closedir(parms.cur_dir.opdir);
		clear_dir_error(parms.cur_dir);
	}
	return (parms);
}

long int	get_time_mod_rint(char *obj)
{
	struct stat		inf;

	if (lstat(obj, &inf) != -1)
		return (inf.st_mtime);
	else
		return (0);
}

int			have_set_gid(t_parms parms)
{
	return ((parms.cur_dir.infent.st_mode & S_ISGID) ? 1 : 0);
}

int			have_sticky(t_parms parms)
{
	return ((parms.cur_dir.infent.st_mode & S_ISVTX) ? 1 : 0);
}

char		*get_time_mod(t_parms parms)
{
	char		*time;

	time = 0;
	time = ctime(&parms.cur_dir.infent.st_mtime);
	return (time);
}
