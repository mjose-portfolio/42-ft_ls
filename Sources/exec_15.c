/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 03:16:02 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 03:31:54 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	exec_var_run(t_parms parms, int j, int y)
{
	int	i;

	i = 0;
	parms.var.j = j;
	parms.var.y = y;
	free(parms.to_list);
	parms.obj_to_list = 1;
	parms = init_info_for_padding(parms);
	if (parms.flags.t && !parms.have_fts)
		sort_tab_dmodif(parms.files, "./", j);
	while (parms.files[i] && !parms.have_fts)
		parms = get_info_for_padding_var(parms, i++);
	run_var_files(parms.files, parms, i);
	run_var_dirs(parms.files, parms.dirs, parms);
}

void	exec_one_dir(t_parms parms)
{
	if (!parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_one_def_rec(parms.to_list[0], parms, 1);
	else if (!parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_one_ft_rec(parms.to_list[0], parms, 1);
	else if (!parms.flags.l && !parms.flags.t && parms.flags.pr)
		exec_one_fr_rec(parms.to_list[0], parms, 1);
	else if (parms.flags.l && !parms.flags.t && !parms.flags.pr)
		exec_one_fl_rec(parms.to_list[0], parms, 1);
	else if (!parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_one_frt_rec(parms.to_list[0], parms, 1);
	else if (parms.flags.l && parms.flags.t && !parms.flags.pr)
		exec_one_flt_rec(parms.to_list[0], parms, 1);
	else if (parms.flags.l && parms.flags.t && parms.flags.pr)
		exec_one_fltr_rec(parms.to_list[0], parms, 1);
}
