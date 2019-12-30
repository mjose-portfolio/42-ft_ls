/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:17:26 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 01:58:56 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		check_for_fts(t_parms parms)
{
	int	i;

	i = 0;
	while (parms.to_list[i])
	{
		if (!ft_strcmp(parms.to_list[i], "fts_open"))
			parms.have_fts = 1;
		i++;
	}
	i = 0;
	if (parms.have_fts)
	{
		while (parms.to_list[i])
		{
			if (!ft_strcmp(parms.to_list[i], "fts_open"))
				parms = init_dir(parms.to_list[i], parms);
			free(parms.to_list[i++]);
		}
		free(parms.to_list);
		return (1);
	}
	return (0);
}

int		check_for_time(t_parms parms)
{
	time_t		sys_time;

	sys_time = time(0);
	if ((sys_time - 15778643) > parms.cur_dir.infent.st_mtime ||
		sys_time < parms.cur_dir.infent.st_mtime)
		return (0);
	else
		return (1);
}

char	*check_path_obj(char *obj)
{
	char	*path;

	if (!is_system(obj) && obj[0] != '/')
		path = path_it(NULL, obj);
	else
		path = ft_strdup(obj);
	return (path);
}

t_parms	check_init_path(char *path, char *obj, t_parms parms)
{
	parms.cur_dir.error = 0;
	if (parms.cur_dir.type == 'd')
		parms = init_path_dir(path, parms);
	else if (is_system(obj))
		parms = init_path_dir(path, parms);
	else if (parms.cur_dir.type == 'l')
		parms = init_path_lnk(path, parms);
	else if (parms.cur_dir.type == 'n')
		parms = init_path_null(path, parms);
	else
		parms = init_path_obj(path, parms);
	return (parms);
}
