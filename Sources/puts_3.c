/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:47:43 by mjose             #+#    #+#             */
/*   Updated: 2018/08/02 20:30:52 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	put_desc(char *dir)
{
	char	*desc;

	desc = NULL;
	ft_putchar('\n');
	ft_putendl(desc = ft_strjoin(dir, ":"));
	free(desc);
}

void	put_total_blocks(t_parms parms)
{
	ft_putstr("total ");
	ft_putnbr(parms.info.totblocks);
	ft_putchar('\n');
}

void	put_time_year(t_parms parms, char *tmp)
{
	char	*year;
	char	*time;

	time = ft_strsub(tmp, 11, 5);
	if (check_for_time(parms))
	{
		ft_putstr(time);
		free(time);
	}
	else
	{
		if (ft_strlen(tmp) > 25)
		{
			year = ft_strsub(tmp, 24, 5);
			ft_putchar(' ');
		}
		else
			year = ft_strsub(tmp, 19, 5);
		ft_putstr(year);
		free(time);
		free(year);
	}
}

void	put_link_obj(char *obj, t_parms parms)
{
	if (parms.flags.gg)
		ft_putstr("\x1B[35m");
	ft_putendl(obj);
	if (parms.flags.gg)
		ft_putstr("\x1B[0m");
}
