/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:05:30 by mjose             #+#    #+#             */
/*   Updated: 2018/07/10 00:36:08 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

static t_sort	exec_qs_dmodif(t_sort s, int li_left, int li_right)
{
	s.pthpiv = convstr_path_if(s.pth, s.piv);
	while (s.lft <= s.rht)
	{
		s.pthlft = convstr_path_if(s.pth, s.tab[s.lft]);
		s.pthrht = convstr_path_if(s.pth, s.tab[s.rht]);
		while (cmp_time(s.pthlft, s.pthpiv) > 0 && s.lft < li_right)
		{
			s.lft++;
			ft_strdel(&s.pthlft);
			s.pthlft = convstr_path_if(s.pth, s.tab[s.lft]);
		}
		while (cmp_time(s.pthpiv, s.pthrht) > 0 && s.rht > li_left)
		{
			s.rht--;
			ft_strdel(&s.pthrht);
			s.pthrht = convstr_path_if(s.pth, s.tab[s.rht]);
		}
		if (s.lft <= s.rht)
		{
			s = swap(s);
			ft_strdel(&s.pthlft);
			ft_strdel(&s.pthrht);
		}
	}
	return (s);
}

static void		qs_dmodif(char **tab, int li_left, int li_right, char *path)
{
	t_sort	sort;

	sort.lft = li_left;
	sort.rht = li_right;
	sort.piv = tab[(sort.lft + sort.rht) / 2];
	sort.tab = tab;
	sort.pth = path;
	sort = exec_qs_dmodif(sort, li_left, li_right);
	if (li_left < sort.rht)
	{
		qs_dmodif(sort.tab, li_left, sort.rht, path);
		ft_strdel(&sort.pthlft);
		ft_strdel(&sort.pthrht);
		ft_strdel(&sort.pthpiv);
	}
	if (li_right > sort.lft)
	{
		qs_dmodif(sort.tab, sort.lft, li_right, path);
		ft_strdel(&sort.pthlft);
		ft_strdel(&sort.pthrht);
		ft_strdel(&sort.pthpiv);
	}
	ft_strdel(&sort.pthpiv);
}

char			**sort_tab_dmodif(char **tab, char *path, int cnt_obj)
{
	qs_dmodif(tab, 0, cnt_obj - 1, path);
	return (tab);
}

static void		qs_alph(char **tab, int li_left, int li_right)
{
	t_sort	s;

	s.lft = li_left;
	s.rht = li_right;
	s.piv = tab[(s.lft + s.rht) / 2];
	s.tab = tab;
	while (s.lft <= s.rht)
	{
		while (ft_strcmp(s.tab[s.lft], s.piv) < 0 && s.lft < li_right)
			s.lft++;
		while (ft_strcmp(s.piv, s.tab[s.rht]) < 0 && s.rht > li_left)
			s.rht--;
		if (s.lft <= s.rht)
			s = swap(s);
	}
	if (li_left < s.rht)
		qs_alph(s.tab, li_left, s.rht);
	if (li_right > s.lft)
		qs_alph(s.tab, s.lft, li_right);
}

char			**sort_alph(char **tab, int cnt_obj)
{
	qs_alph(tab, 0, cnt_obj - 1);
	return (tab);
}
