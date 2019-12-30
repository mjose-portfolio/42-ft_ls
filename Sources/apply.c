/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:05:35 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 02:57:59 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	apply_long(t_parms parms, char *path_ent)
{
	ft_putchar(type_obj(parms));
	put_rights(parms, path_ent);
	put_nlinks(parms);
	if (!parms.flags.g)
		put_user(parms);
	if (!parms.flags.o)
		put_group(parms);
	put_size(parms);
	put_mtime(parms);
	ft_putchar(' ');
}
