/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:21:16 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:49:38 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	print_list_lnk(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = 0;
	while (list[l])
	{
		path_ent = path_it(parms.cur_dir.path_obj, list[l]);
		lstat(path_ent, &parms.cur_dir.infent);
		if ((type = type_obj(parms)) == 'l')
			put_link_obj(list[l], parms);
		else
		{
			if (type == 'd')
				put_dir(list[l], parms);
			else
				ft_putendl(list[l]);
		}
		free(list[l++]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}

void	print_list_flr(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = parms.cur_dir.cobjs - 1;
	put_total_blocks(parms);
	while (l > -1)
	{
		path_ent = path_it(parms.cur_dir.path_dir, list[l]);
		lstat(path_ent, &parms.cur_dir.infent);
		apply_long(parms, path_ent);
		if ((type = type_obj(parms)) == 'l')
			put_link(list[l], path_ent, parms);
		else
		{
			if (type == 'd')
				put_dir(list[l], parms);
			else
				ft_putendl(list[l]);
		}
		free(list[l--]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}

void	print_list_fl(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = 0;
	put_total_blocks(parms);
	while (list[l])
	{
		path_ent = path_it(parms.cur_dir.path_dir, list[l]);
		lstat(path_ent, &parms.cur_dir.infent);
		apply_long(parms, path_ent);
		if ((type = type_obj(parms)) == 'l')
			put_link(list[l], path_ent, parms);
		else
		{
			if (type == 'd')
				put_dir(list[l], parms);
			else
				ft_putendl(list[l]);
		}
		free(list[l++]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}

void	print_list_fr(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = parms.cur_dir.cobjs - 1;
	while (l > -1)
	{
		path_ent = path_it(parms.cur_dir.path_dir, list[l]);
		lstat(path_ent, &parms.cur_dir.infent);
		if ((type = type_obj(parms)) == 'l')
			put_link_obj(list[l], parms);
		else
		{
			if (type == 'd')
				put_dir(list[l], parms);
			else
				ft_putendl(list[l]);
		}
		free(list[l--]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}

void	print_list(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = 0;
	while (list[l])
	{
		path_ent = path_it(parms.cur_dir.path_dir, list[l]);
		lstat(path_ent, &parms.cur_dir.infent);
		if ((type = type_obj(parms)) == 'l')
			put_link_obj(list[l], parms);
		else
		{
			if (type == 'd')
				put_dir(list[l], parms);
			else
				ft_putendl(list[l]);
		}
		free(list[l++]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}
