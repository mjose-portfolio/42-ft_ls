/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_right_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:41:48 by mjose             #+#    #+#             */
/*   Updated: 2018/06/22 21:55:42 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void				put_rights_usrsp(t_parms parms)
{
	if (rights_user(parms) == 7)
		ft_putstr("rws");
	else if (rights_user(parms) == 6)
		ft_putstr("rwS");
	else if (rights_user(parms) == 5)
		ft_putstr("r-s");
	else if (rights_user(parms) == 4)
		ft_putstr("r-S");
	else if (rights_user(parms) == 3)
		ft_putstr("-ws");
	else if (rights_user(parms) == 2)
		ft_putstr("-wS");
	else if (rights_user(parms) == 1)
		ft_putstr("--s");
	else
		ft_putstr("--S");
}

void				put_rights_grpsp(t_parms parms)
{
	if (rights_group(parms) == 7)
		ft_putstr("rws");
	else if (rights_group(parms) == 6)
		ft_putstr("rwS");
	else if (rights_group(parms) == 5)
		ft_putstr("r-s");
	else if (rights_group(parms) == 4)
		ft_putstr("r-S");
	else if (rights_group(parms) == 3)
		ft_putstr("-ws");
	else if (rights_group(parms) == 2)
		ft_putstr("-wS");
	else if (rights_group(parms) == 1)
		ft_putstr("--s");
	else
		ft_putstr("--S");
}

void				put_rights_othsp(t_parms parms)
{
	if (rights_others(parms) == 7)
		ft_putstr("rwt");
	else if (rights_others(parms) == 6)
		ft_putstr("rwT");
	else if (rights_others(parms) == 5)
		ft_putstr("r-t");
	else if (rights_others(parms) == 4)
		ft_putstr("r-T");
	else if (rights_others(parms) == 3)
		ft_putstr("-wt");
	else if (rights_others(parms) == 2)
		ft_putstr("-wT");
	else if (rights_others(parms) == 1)
		ft_putstr("--t");
	else
		ft_putstr("--T");
}
