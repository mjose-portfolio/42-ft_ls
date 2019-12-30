/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:31:39 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:39:01 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

unsigned long	get_block_size(t_parms parms)
{
	unsigned long	block_size;

	block_size = 0;
	block_size = parms.cur_dir.infent.st_blocks;
	return (block_size);
}

int				get_nlinks(t_parms parms)
{
	int		nlinks;

	nlinks = 0;
	nlinks = parms.cur_dir.infent.st_nlink;
	return (nlinks);
}

char			*get_user(t_parms parms)
{
	struct passwd	*pinf;
	char			*user;
	int				uid;

	user = NULL;
	uid = parms.cur_dir.infent.st_uid;
	if (uid == 0)
		return ("root");
	else if (uid == 4389)
		return ("4389");
	pinf = getpwuid(uid);
	user = pinf->pw_name;
	return (user);
}

char			*get_group(t_parms parms)
{
	struct group	*ginf;
	char			*group;
	int				gid;

	group = NULL;
	gid = parms.cur_dir.infent.st_gid;
	ginf = getgrgid(gid);
	group = ginf->gr_name;
	return (group);
}

t_parms			get_info_for_padding(t_parms parms, int ctrl, char type)
{
	int		tmp;
	int		len;

	if (!ctrl)
	{
		tmp = get_block_size(parms);
		parms.info.totblocks += tmp;
	}
	tmp = get_nlinks(parms);
	len = ft_intlen(tmp, 10);
	parms.infsiz.lnk = (len > parms.infsiz.lnk) ? len : parms.infsiz.lnk;
	len = ft_strlen(get_user(parms));
	parms.infsiz.usr = (len > parms.infsiz.usr) ? len : parms.infsiz.usr;
	len = ft_strlen(get_group(parms));
	parms.infsiz.grp = (len > parms.infsiz.grp) ? len : parms.infsiz.grp;
	if (type == 'b' || type == 'c')
		parms = get_info_for_pad_majmin(parms);
	tmp = get_size(parms);
	len = ft_intlen(tmp, 10);
	parms.infsiz.siz = (len > parms.infsiz.siz) ? len : parms.infsiz.siz;
	return (parms);
}
