/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:16:28 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 21:03:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_flags	flagged_a(t_flags flags)
{
	flags.ga = 0;
	flags.a = 1;
	return (flags);
}

t_flags	flagged_col(t_flags flags)
{
	flags.col = 1;
	flags.l = 0;
	return (flags);
}

t_flags	flagged(t_flags flags, char *parm, int c)
{
	flags.error = 0;
	flags.col = 1;
	while (parm[c])
	{
		flags = flag_it(flags, parm[c]);
		if (flags.error)
			return (flags);
		c++;
	}
	flags.error = 0;
	return (flags);
}

t_flags	not_flagged(t_flags flags)
{
	flags.error = 0;
	flags.col = 1;
	flags.gr = 0;
	flags.a = 0;
	flags.l = 0;
	flags.pr = 0;
	flags.t = 0;
	flags.g = 0;
	flags.gg = 0;
	flags.ga = 0;
	flags.o = 0;
	return (flags);
}

t_flags	error_flag(t_flags flags)
{
	flags.error = 1;
	flags.col = 0;
	flags.gr = 0;
	flags.a = 0;
	flags.l = 0;
	flags.pr = 0;
	flags.t = 0;
	flags.g = 0;
	flags.gg = 0;
	flags.ga = 0;
	flags.o = 0;
	return (flags);
}
