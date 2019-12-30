/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:28:47 by mjose             #+#    #+#             */
/*   Updated: 2018/06/22 21:53:42 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void				put_rights_user(t_parms parms)
{
	if (rights_user(parms) == 7)
		ft_putstr("rwx");
	else if (rights_user(parms) == 6)
		ft_putstr("rw-");
	else if (rights_user(parms) == 5)
		ft_putstr("r-x");
	else if (rights_user(parms) == 4)
		ft_putstr("r--");
	else if (rights_user(parms) == 3)
		ft_putstr("-wx");
	else if (rights_user(parms) == 2)
		ft_putstr("-w-");
	else if (rights_user(parms) == 1)
		ft_putstr("--x");
	else
		ft_putstr("---");
}

void				put_rights_group(t_parms parms)
{
	if (rights_group(parms) == 7)
		ft_putstr("rwx");
	else if (rights_group(parms) == 6)
		ft_putstr("rw-");
	else if (rights_group(parms) == 5)
		ft_putstr("r-x");
	else if (rights_group(parms) == 4)
		ft_putstr("r--");
	else if (rights_group(parms) == 3)
		ft_putstr("-wx");
	else if (rights_group(parms) == 2)
		ft_putstr("-w-");
	else if (rights_group(parms) == 1)
		ft_putstr("--x");
	else
		ft_putstr("---");
}

void				put_rights_others(t_parms parms)
{
	if (rights_others(parms) == 7)
		ft_putstr("rwx");
	else if (rights_others(parms) == 6)
		ft_putstr("rw-");
	else if (rights_others(parms) == 5)
		ft_putstr("r-x");
	else if (rights_others(parms) == 4)
		ft_putstr("r--");
	else if (rights_others(parms) == 3)
		ft_putstr("-wx");
	else if (rights_others(parms) == 2)
		ft_putstr("-w-");
	else if (rights_others(parms) == 1)
		ft_putstr("--x");
	else
		ft_putstr("---");
}
