/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:20:01 by mjose             #+#    #+#             */
/*   Updated: 2018/06/22 21:52:41 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int			have_set_uid(t_parms parms)
{
	return ((parms.cur_dir.infent.st_mode & S_ISUID) ? 1 : 0);
}

int			get_major(t_parms parms)
{
	int		major;

	major = 0;
	major = major(parms.cur_dir.infent.st_rdev);
	return (major);
}

int			get_minor(t_parms parms)
{
	int			minor;

	minor = 0;
	minor = minor(parms.cur_dir.infent.st_rdev);
	return (minor);
}

t_parms		get_info_for_pad_majmin(t_parms parms)
{
	int		tmp;
	int		len;

	tmp = get_major(parms);
	len = ft_intlen(tmp, 10);
	parms.infsiz.maj = (len > parms.infsiz.maj) ? len : parms.infsiz.maj;
	tmp = get_minor(parms);
	len = ft_intlen(tmp, 10);
	parms.infsiz.min = (len > parms.infsiz.min) ? len : parms.infsiz.min;
	return (parms);
}

int			get_size(t_parms parms)
{
	int			size;

	size = 0;
	size = parms.cur_dir.infent.st_size;
	return (size);
}
