/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 02:41:31 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 03:12:47 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	print_tab_dirs_rev(t_parms parms, char **dirs)
{
	while (parms.var.i > -1 && dirs[parms.var.i])
	{
		parms.is_var = 0;
		if (parms.var.j)
			ft_putchar('\n');
		ft_putstr(dirs[parms.var.i]);
		ft_putendl(":");
		parms.to_list = (char **)malloc(sizeof(char *) * 2);
		parms.to_list[0] = dirs[parms.var.i--];
		exec(parms);
		parms.var.j++;
	}
	free(dirs);
}

void	print_tab_dirs_def(t_parms parms, char **dirs)
{
	while (dirs[parms.var.i])
	{
		parms.is_var = 0;
		if (parms.var.j)
			ft_putchar('\n');
		ft_putstr(dirs[parms.var.i]);
		ft_putendl(":");
		parms.to_list = (char **)malloc(sizeof(char *) * 2);
		parms.to_list[0] = dirs[parms.var.i++];
		exec(parms);
		parms.var.j++;
	}
	free(dirs);
}
