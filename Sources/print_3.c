/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 06:11:50 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 02:13:31 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	**print_list_lnk_flr_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = parms.cur_dir.cobjs - 1;
	if (parms.cur_dir.cobjs)
		put_total_blocks(parms);
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_lnk_flr_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_lnk_fl_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = 0;
	if (parms.cur_dir.cobjs)
		put_total_blocks(parms);
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_lnk_fl_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_lnk_fr_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = parms.cur_dir.cobjs - 1;
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_lnk_fr_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}

char	**print_list_lnk_rec(char **list, t_parms parms)
{
	t_rec	rec;

	rec.l = 0;
	rec.tab_dirs = NULL;
	if (parms.cur_dir.cdirs)
		rec.tab_dirs = crt_tab_void(parms.cur_dir.cdirs + 1);
	rec.i = 0;
	rec = tab_it_for_print_lnk_rec(rec, parms, list);
	free(list);
	clear_dir_error(parms.cur_dir);
	return (rec.tab_dirs);
}
