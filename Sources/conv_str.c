/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:25:46 by mjose             #+#    #+#             */
/*   Updated: 2018/07/09 23:38:01 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char		*convstr_path_if(char *dir, char *obj)
{
	char	*new_path;

	if (!ft_strcmp(dir, "./") || !ft_strcmp(dir, "."))
	{
		if (obj[0] == '/')
			new_path = ft_strdup(obj);
		else
			new_path = path_it(dir, obj);
	}
	else
		new_path = path_it(dir, obj);
	return (new_path);
}

static char	*path_it_nulldir(char *obj)
{
	char	*path;

	if (!ft_strncmp(obj, "..", 2))
		path = ft_strdup(obj);
	else if (!ft_strncmp(obj, "./", 2))
		path = ft_strdup(obj);
	else if (!ft_strncmp(obj, "/", 1))
		path = ft_strdup(obj);
	else
		path = ft_strjoin("./", obj);
	return (path);
}

char		*path_it(char *dir, char *obj)
{
	char	*tmp;
	char	*path;

	if (!dir)
		path = path_it_nulldir(obj);
	else
	{
		tmp = ft_strjoin(dir, "/");
		path = ft_strjoin(tmp, obj);
		free(tmp);
	}
	return (path);
}

char		*rmv_path_frm_obj(char *path)
{
	int		total_l;
	int		i;
	int		ctrl;
	char	*obj;

	total_l = ft_strlen(path);
	i = 0;
	ctrl = 0;
	while (i != total_l + 1)
	{
		if (path[i] == '/')
			ctrl = i;
		i++;
	}
	obj = (char *)malloc(sizeof(char) * (total_l - ctrl));
	if (obj)
	{
		i = 0;
		ctrl++;
		while (path[ctrl])
			obj[i++] = path[ctrl++];
		obj[i] = '\0';
		return (obj);
	}
	return (NULL);
}

char		*rmv_obj_frm_path(char *path)
{
	int		i;
	int		ctrl;
	char	*obj;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			ctrl = i;
		i++;
	}
	obj = (char *)malloc(sizeof(char) * (ctrl) + 2);
	if (obj)
	{
		i = 0;
		while (i != ctrl)
		{
			obj[i] = path[i];
			i++;
		}
		obj[i] = path[i];
		obj[i + 1] = '\0';
		return (obj);
	}
	return (NULL);
}
