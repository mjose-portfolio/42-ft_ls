/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 22:19:11 by mjose             #+#    #+#             */
/*   Updated: 2018/08/11 18:02:54 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**print_list_flr_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = parms.cur_dir.cobjs - 1;
	if (parms.cur_dir.cobjs)
		put_total_blocks(parms);
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_flr_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_fl_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = 0;
	if (parms.cur_dir.cobjs)
		put_total_blocks(parms);
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_fl_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_fr_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = parms.cur_dir.cobjs - 1;
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_fr_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = 0;
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

void	print_list_lnk_fr(char **list, t_parms parms)
{
	int		l;
	char	*path_ent;
	char	type;

	l = parms.cur_dir.cobjs - 1;
	while (l > -1)
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
		free(list[l--]);
		free(path_ent);
	}
	free(list);
	clear_dir_error(parms.cur_dir);
}
