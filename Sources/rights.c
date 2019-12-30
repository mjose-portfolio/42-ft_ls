/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:35:05 by mjose             #+#    #+#             */
/*   Updated: 2018/06/22 21:54:45 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		rights_user(t_parms parms)
{
	int			right;

	right = (parms.cur_dir.infent.st_mode & S_IRUSR) ? 4 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IWUSR) ? 2 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IXUSR) ? 1 : 0;
	return (right);
}

int		rights_group(t_parms parms)
{
	int			right;

	right = (parms.cur_dir.infent.st_mode & S_IRGRP) ? 4 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IWGRP) ? 2 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IXGRP) ? 1 : 0;
	return (right);
}

int		rights_others(t_parms parms)
{
	int			right;

	right = (parms.cur_dir.infent.st_mode & S_IROTH) ? 4 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IWOTH) ? 2 : 0;
	right += (parms.cur_dir.infent.st_mode & S_IXOTH) ? 1 : 0;
	return (right);
}
