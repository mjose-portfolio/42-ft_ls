/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:26:08 by mjose             #+#    #+#             */
/*   Updated: 2017/11/18 15:05:56 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (start--)
				s++;
			ft_strncpy(str, s, len);
			str[len] = '\0';
		}
		return (str);
	}
	return (NULL);
}
