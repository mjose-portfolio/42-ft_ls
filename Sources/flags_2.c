/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 20:24:17 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 21:03:38 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_flags	flagged_o(t_flags flags)
{
	flags.col = 0;
	flags.o = 1;
	flags.l = 1;
	return (flags);
}

t_flags	flagged_ga(t_flags flags)
{
	if (!flags.a)
		flags.ga = 1;
	else
		flags.ga = 0;
	return (flags);
}

t_flags	flagged_g(t_flags flags)
{
	flags.col = 0;
	flags.g = 1;
	flags.l = 1;
	return (flags);
}

t_flags	flagged_l(t_flags flags)
{
	flags.col = 0;
	flags.l = 1;
	return (flags);
}

t_flags	flag_it(t_flags flags, char c)
{
	if (c == '1')
		flags = flagged_col(flags);
	else if (c == 'R')
		flags.gr = 1;
	else if (c == 'a')
		flags = flagged_a(flags);
	else if (c == 'l')
		flags = flagged_l(flags);
	else if (c == 'r')
		flags.pr = 1;
	else if (c == 't')
		flags.t = 1;
	else if (c == 'g')
		flags = flagged_g(flags);
	else if (c == 'G')
		flags.gg = 1;
	else if (c == 'A')
		flags = flagged_ga(flags);
	else if (c == 'o')
		flags = flagged_o(flags);
	else
		return (error_flag(flags));
	return (flags);
}
