/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:10:22 by mjose             #+#    #+#             */
/*   Updated: 2018/07/23 21:46:12 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	put_mtime(t_parms parms)
{
	char	*month;
	char	*day;
	char	*tmp;

	tmp = get_time_mod(parms);
	month = ft_strsub(tmp, 4, 4);
	day = ft_strsub(tmp, 8, 3);
	ft_putchar(' ');
	ft_putstr(month);
	ft_putstr(day);
	put_time_year(parms, tmp);
	free(month);
	free(day);
}

void	put_group(t_parms parms)
{
	char	*group;
	int		tmpl;

	group = get_group(parms);
	tmpl = ft_strlen(group);
	ft_putchar(' ');
	ft_putstr(group);
	if (parms.infsiz.grp)
	{
		while (tmpl < parms.infsiz.grp)
		{
			ft_putchar(' ');
			tmpl++;
		}
	}
}

void	put_user(t_parms parms)
{
	char	*user;
	int		tmpl;

	user = get_user(parms);
	tmpl = ft_strlen(user);
	ft_putchar(' ');
	ft_putstr(user);
	if (parms.infsiz.usr)
	{
		while (tmpl < parms.infsiz.usr + 1)
		{
			ft_putchar(' ');
			tmpl++;
		}
	}
}

void	put_nlinks(t_parms parms)
{
	int		nlinks;
	int		tmpl;

	nlinks = get_nlinks(parms);
	tmpl = ft_intlen(nlinks, 10);
	if (parms.infsiz.lnk)
	{
		while (parms.infsiz.lnk > tmpl)
		{
			ft_putchar(' ');
			tmpl++;
		}
	}
	ft_putnbr(nlinks);
}

void	put_rights(t_parms parms, char *path_ent)
{
	acl_t	acl;
	char	list[1024];

	if (!have_set_uid(parms))
		put_rights_user(parms);
	else
		put_rights_usrsp(parms);
	if (!have_set_gid(parms))
		put_rights_group(parms);
	else
		put_rights_grpsp(parms);
	if (!have_sticky(parms))
		put_rights_others(parms);
	else
		put_rights_othsp(parms);
	if ((listxattr(path_ent, list, 1024, XATTR_SHOWCOMPRESSION)) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_file(path_ent, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free(acl);
	}
	else
		ft_putchar(' ');
	ft_putchar(' ');
}
