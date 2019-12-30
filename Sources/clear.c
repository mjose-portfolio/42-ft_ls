/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:04:16 by mjose             #+#    #+#             */
/*   Updated: 2018/08/04 03:49:36 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_dir	reset_dir_error(t_dir cur_dir)
{
	if (cur_dir.error != 0)
	{
		if (cur_dir.path_dir != NULL)
			free(cur_dir.path_dir);
		if (cur_dir.path_obj != NULL)
			free(cur_dir.path_obj);
		if (cur_dir.obj != NULL)
			free(cur_dir.obj);
		cur_dir.error = 0;
	}
	return (cur_dir);
}

void	clear_dir(t_dir cur_dir)
{
	if (!cur_dir.error)
	{
		if (cur_dir.path_dir)
			free(cur_dir.path_dir);
		if (cur_dir.path_obj)
			free(cur_dir.path_obj);
		if (cur_dir.obj)
			free(cur_dir.obj);
	}
}

void	clear_dir_error(t_dir cur_dir)
{
	if (cur_dir.path_dir != NULL)
		free(cur_dir.path_dir);
	if (cur_dir.path_obj != NULL)
		free(cur_dir.path_obj);
	if (cur_dir.obj != NULL)
		free(cur_dir.obj);
}
