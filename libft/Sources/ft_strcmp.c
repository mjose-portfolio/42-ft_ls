/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:22:20 by mjose             #+#    #+#             */
/*   Updated: 2018/08/10 04:13:28 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char s11;
	unsigned char s22;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL || s2 == NULL)
		return (-122);
	s11 = *s1;
	s22 = *s2;
	if (!s11 && !s22)
		return (0);
	else if (s11 != s22)
		return (s11 - s22);
	return (ft_strcmp(++s1, ++s2));
}
