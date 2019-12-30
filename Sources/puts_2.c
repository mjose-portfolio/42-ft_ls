/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 23:38:00 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 03:55:03 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	put_dir(char *obj, t_parms parms)
{
	if (parms.flags.gg)
		ft_putstr("\x1B[36m");
	ft_putendl(obj);
	if (parms.flags.gg)
		ft_putstr("\x1B[0m");
}

void	put_link(char *obj, char *path, t_parms parms)
{
	int		len;
	char	buf[1024];

	len = 0;
	if (parms.flags.gg)
		ft_putstr("\x1B[35m");
	ft_putstr(obj);
	if (parms.flags.gg)
		ft_putstr("\x1B[0m");
	ft_putstr(" -> ");
	if ((len = readlink(path, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_putendl(buf);
}

void	put_major(t_parms parms)
{
	int		major;
	int		tmpl;

	major = get_major(parms);
	if (parms.infsiz.maj == 1)
		ft_putchar(' ');
	else
	{
		tmpl = ft_intlen(major, 10);
		while (parms.infsiz.maj > tmpl)
		{
			ft_putchar(' ');
			tmpl++;
		}
		ft_putstr("   ");
	}
	ft_putnbr(major);
	ft_putstr(", ");
}

void	put_minor(t_parms parms)
{
	int		minor;
	int		tmpl;

	minor = get_minor(parms);
	if (parms.infsiz.min == 1)
		ft_putchar(' ');
	else
	{
		tmpl = ft_intlen(minor, 10);
		while (parms.infsiz.min > tmpl)
		{
			ft_putchar(' ');
			tmpl++;
		}
	}
	ft_putnbr(minor);
}

void	put_size(t_parms parms)
{
	off_t	size;
	int		tmpl;

	if (type_obj(parms) == 'c' || type_obj(parms) == 'b')
	{
		put_major(parms);
		put_minor(parms);
		return ;
	}
	size = get_size(parms);
	tmpl = ft_intlen(size, 10);
	parms.infsiz.siz = (parms.infsiz.min) ?
		parms.infsiz.siz + parms.infsiz.min + 1 : parms.infsiz.siz;
	if (parms.infsiz.siz)
		while (parms.infsiz.siz + 1 > tmpl)
		{
			ft_putchar(' ');
			tmpl++;
		}
	ft_putchar(' ');
	ft_putnbr(size);
}
