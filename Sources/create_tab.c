/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:35:28 by mjose             #+#    #+#             */
/*   Updated: 2018/08/01 18:53:59 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char		**crt_tab_void(int num_objs)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (num_objs));
	if (tab)
		return (tab);
	return (NULL);
}

static char	**fill_tab_parm(int p, int num_parms, char **parms, char **tab_parm)
{
	int		l;
	int		ctrl;

	l = 0;
	ctrl = 0;
	while (p != num_parms)
	{
		if (!ft_strcmp(parms[p], """"))
		{
			tab_parm[l] = ft_strdup("fts_open");
			ctrl = 1;
			l++;
		}
		else if (!ctrl)
		{
			tab_parm[l] = ft_strdup(parms[p]);
			l++;
		}
		p++;
	}
	tab_parm[l] = NULL;
	return (tab_parm);
}

static char	**crt_tab_void_for_parms(int num_parms, char **parms, int p)
{
	char	**tab_parm;

	if ((num_parms - p + 1) == 1)
		tab_parm = NULL;
	else if (!ft_strcmp(parms[p], """"))
		tab_parm = (char **)malloc(sizeof(char *) * 2);
	else
		tab_parm = (char **)malloc(sizeof(char *) * (num_parms - p + 1));
	return (tab_parm);
}

char		**crt_tab_parms(int num_parms, char **parms, int p)
{
	char	**tab_parm;

	tab_parm = crt_tab_void_for_parms(num_parms, parms, p);
	if (!tab_parm)
		return (NULL);
	return (fill_tab_parm(p, num_parms, parms, tab_parm));
}
