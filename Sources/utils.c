/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:15:52 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 03:39:50 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	run_var_files(char **files, t_parms parms, int i)
{
	if (!parms.flags.pr && !parms.have_fts)
	{
		i = 0;
		while (files[i])
		{
			parms.is_var = 1;
			parms.to_list = (char **)malloc(sizeof(char *) * 2);
			parms.to_list[0] = files[i];
			exec(parms);
			i++;
		}
	}
	else if (!parms.have_fts)
	{
		i--;
		while (i > -1)
		{
			parms.is_var = 1;
			parms.to_list = (char **)malloc(sizeof(char *) * 2);
			parms.to_list[0] = files[i];
			exec(parms);
			i--;
		}
	}
	free(files);
}

void	free_tabs_var(char **files, char **dirs, t_parms parms)
{
	int	i;

	i = 0;
	if (files)
		if (parms.var.have_files)
		{
			while (files[i])
				free(files[i++]);
			i = 0;
			free(files);
		}
	if (dirs)
		if (parms.var.have_dirs)
		{
			while (dirs[i])
				free(dirs[i++]);
			i = 0;
			free(dirs);
		}
}

void	run_var_dirs(char **files, char **dirs, t_parms parms)
{
	if (!parms.flags.pr && !parms.have_fts)
	{
		parms.var.i = 0;
		print_tab_dirs_def(parms, dirs);
	}
	else if (!parms.have_fts)
	{
		parms.var.i = parms.var.y - 1;
		print_tab_dirs_rev(parms, dirs);
	}
	else if (parms.have_fts)
		free_tabs_var(files, dirs, parms);
}

int		cmp_time(char *obj1, char *obj2)
{
	if (obj1 && obj2)
	{
		if (get_time_mod_rint(obj1) > get_time_mod_rint(obj2))
			return (1);
		else if (get_time_mod_rint(obj1) == get_time_mod_rint(obj2))
			return (ft_strcmp(obj1, obj2) < 0);
		else
			return (0);
	}
	return (0);
}

t_sort	swap(t_sort s)
{
	s.tmp = s.tab[s.lft];
	s.tab[s.lft] = s.tab[s.rht];
	s.tab[s.rht] = s.tmp;
	s.lft++;
	s.rht--;
	return (s);
}
