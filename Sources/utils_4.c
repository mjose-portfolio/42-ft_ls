/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 00:54:29 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 01:56:20 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_rec	tab_it_for_print_lnk_flr_rec(t_rec rec, t_parms parms, char **list)
{
	while (rec.l > -1)
	{
		rec.path_ent = path_it(parms.cur_dir.path_obj, list[rec.l]);
		parms.cur_dir.error = lstat(rec.path_ent, &parms.cur_dir.infent);
		apply_long(parms, rec.path_ent);
		if ((rec.type = type_obj(parms)) == 'l')
			put_link(list[rec.l], rec.path_ent, parms);
		else if (parms.cur_dir.cdirs != 0)
		{
			if ((rec.type == 'd' && parms.cur_dir.cdirs) ||
				parms.cur_dir.error < 0)
				rec = put_and_tab_dir(rec, list, parms);
			else
				ft_putendl(list[rec.l]);
		}
		else if (rec.type == 'd')
			put_dir(list[rec.l], parms);
		else
			ft_putendl(list[rec.l]);
		free(list[rec.l--]);
		free(rec.path_ent);
	}
	return (rec);
}

t_rec	tab_it_for_print_lnk_fl_rec(t_rec rec, t_parms parms, char **list)
{
	while (list[rec.l])
	{
		rec.path_ent = path_it(parms.cur_dir.path_obj, list[rec.l]);
		parms.cur_dir.error = lstat(rec.path_ent, &parms.cur_dir.infent);
		apply_long(parms, rec.path_ent);
		if ((rec.type = type_obj(parms)) == 'l')
			put_link(list[rec.l], rec.path_ent, parms);
		else if (parms.cur_dir.cdirs != 0)
		{
			if ((rec.type == 'd' && parms.cur_dir.cdirs) ||
				parms.cur_dir.error < 0)
				rec = put_and_tab_dir(rec, list, parms);
			else
				ft_putendl(list[rec.l]);
		}
		else if (rec.type == 'd')
			put_dir(list[rec.l], parms);
		else
			ft_putendl(list[rec.l]);
		free(list[rec.l++]);
		free(rec.path_ent);
	}
	return (rec);
}

t_rec	tab_it_for_print_lnk_fr_rec(t_rec rec, t_parms parms, char **list)
{
	while (rec.l > -1)
	{
		rec.path_ent = path_it(parms.cur_dir.path_obj, list[rec.l]);
		parms.cur_dir.error = lstat(rec.path_ent, &parms.cur_dir.infent);
		if ((rec.type = type_obj(parms)) == 'l')
			put_link_obj(list[rec.l], parms);
		else if (parms.cur_dir.cdirs != 0)
		{
			if ((rec.type == 'd' && parms.cur_dir.cdirs) ||
				parms.cur_dir.error < 0)
				rec = put_and_tab_dir(rec, list, parms);
			else
				ft_putendl(list[rec.l]);
		}
		else if (rec.type == 'd')
			put_dir(list[rec.l], parms);
		else
			ft_putendl(list[rec.l]);
		free(list[rec.l--]);
		free(rec.path_ent);
	}
	return (rec);
}

t_rec	tab_it_for_print_lnk_rec(t_rec rec, t_parms parms, char **list)
{
	while (list[rec.l])
	{
		rec.path_ent = path_it(parms.cur_dir.path_obj, list[rec.l]);
		parms.cur_dir.error = lstat(rec.path_ent, &parms.cur_dir.infent);
		if ((rec.type = type_obj(parms)) == 'l')
			put_link_obj(list[rec.l], parms);
		else if (parms.cur_dir.cdirs != 0)
		{
			if ((rec.type == 'd' && parms.cur_dir.cdirs) ||
				parms.cur_dir.error < 0)
				rec = put_and_tab_dir(rec, list, parms);
			else
				ft_putendl(list[rec.l]);
		}
		else if (rec.type == 'd')
			put_dir(list[rec.l], parms);
		else
			ft_putendl(list[rec.l]);
		free(list[rec.l++]);
		free(rec.path_ent);
	}
	return (rec);
}

t_rec	tab_it_for_print_flr_rec(t_rec rec, t_parms parms, char **list)
{
	while (rec.l > -1)
	{
		rec.path_ent = path_it(parms.cur_dir.path_dir, list[rec.l]);
		parms.cur_dir.error = lstat(rec.path_ent, &parms.cur_dir.infent);
		apply_long(parms, rec.path_ent);
		if ((rec.type = type_obj(parms)) == 'l')
			put_link(list[rec.l], rec.path_ent, parms);
		else if (parms.cur_dir.cdirs != 0)
		{
			if ((rec.type == 'd' && parms.cur_dir.cdirs) ||
				parms.cur_dir.error < 0)
				rec = put_and_tab_dir(rec, list, parms);
			else
				ft_putendl(list[rec.l]);
		}
		else if (rec.type == 'd')
			put_dir(list[rec.l], parms);
		else
			ft_putendl(list[rec.l]);
		free(list[rec.l--]);
		free(rec.path_ent);
	}
	return (rec);
}
