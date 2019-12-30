/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:23:20 by mjose             #+#    #+#             */
/*   Updated: 2018/08/08 22:27:21 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	check_flags_error(char **parms, int p, int c)
{
	while (parms[p][c] != '-' && parms[p][c] != '\0')
		c++;
	if (parms[p][c] == '-')
		print_error_flags('-');
	else
	{
		c = 1;
		while ((parms[p][c] == 'R' || parms[p][c] == 'a' ||
				parms[p][c] == 'l' || parms[p][c] == 'r' ||
				parms[p][c] == 't' || parms[p][c] == '1' ||
				parms[p][c] == 'g' || parms[p][c] == 'G' ||
				parms[p][c] == 'A' || parms[p][c] == 'o')
				&& (parms[p][c] != '\0'))
			c++;
		print_error_flags(parms[p][c]);
	}
}

t_flags	check_flags(t_flags flags, char *parm)
{
	int		i;

	i = 0;
	if (parm && parm[i] == '-')
	{
		i++;
		if (parm[i] != 'R' && parm[i] != 'a' && parm[i] != 'l' &&
			parm[i] != 't' && parm[i] != 'r' && parm[i] != '1' &&
			parm[i] != 'g' && parm[i] != 'G' && parm[i] != 'A' &&
			parm[i] != 'o')
			return (error_flag(flags));
		flags.col = 0;
		return (flagged(flags, parm, i));
	}
	return (not_flagged(flags));
}

t_parms	init_flags(t_parms params, char **parms, int p, int c)
{
	params.flags = check_flags(params.flags, parms[p]);
	if (params.flags.error)
		check_flags_error(parms, p, c);
	return (params);
}

t_parms	check_parms(int num_parms, char **parms)
{
	int		p;
	int		ctrl;
	t_parms	params;

	p = 1;
	ctrl = 0;
	params.flags = not_flagged(params.flags);
	if (num_parms != 1)
	{
		while (p != num_parms && parms[p][0] == '-' && parms[p][1] && !ctrl)
		{
			if (ft_strcmp(parms[p], "--"))
				params = init_flags(params, parms, p, 1);
			else
				ctrl = p;
			p++;
		}
		params.to_list = crt_tab_parms(num_parms, parms, p);
		params.obj_to_list = num_parms - p;
		params.is_var = 0;
	}
	else
		params.obj_to_list = 0;
	return (params);
}

int		main(int ac, char **av)
{
	t_parms	parms;

	parms = check_parms(ac, av);
	parms.var.have_dirs = 0;
	parms.var.have_files = 0;
	parms.have_fts = 0;
	if (parms.flags.error)
		return (1);
	else
		exec(parms);
	return (0);
}
