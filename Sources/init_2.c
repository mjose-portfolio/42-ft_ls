/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:40:39 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:40:20 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_parms	init_path_null(char *path, t_parms parms)
{
	parms.cur_dir.path_dir = NULL;
	parms.cur_dir.path_obj = ft_strdup(path);
	parms.cur_dir.obj = NULL;
	parms.cur_dir.path_lnk[0] = '\0';
	return (parms);
}

t_parms	init_info_for_padding(t_parms parms)
{
	if (!parms.is_var)
	{
		parms.info.totblocks = 0;
		parms.infsiz.lnk = 0;
		parms.infsiz.usr = 0;
		parms.infsiz.grp = 0;
		parms.infsiz.maj = 0;
		parms.infsiz.min = 0;
		parms.infsiz.siz = 0;
	}
	return (parms);
}
