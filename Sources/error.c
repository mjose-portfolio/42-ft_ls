/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:50:14 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:01:19 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	print_error_flags(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-RAaGglort] [file ...]", 2);
}

void	print_error_open(char *obj, t_parms parms)
{
	char	*err;
	char	*tmp;

	if (obj[0] == '/')
		tmp = rmv_path_frm_obj(obj);
	else if (obj[0] == '.' && obj[1] == '/')
		tmp = rmv_path_frm_obj(obj);
	else
		tmp = ft_strdup(obj);
	if ((parms.cur_dir.error = lstat(obj, &parms.cur_dir.infent)) < 0)
		err = ft_strjoin("ft_ls: ", tmp);
	else
	{
		err = ft_strnew(7 + ft_strlen(tmp));
		err = ft_strcpy(err, "ft_ls: ");
		err = ft_strcat(err, tmp);
	}
	perror(err);
	ft_strdel(&err);
	free(tmp);
}
