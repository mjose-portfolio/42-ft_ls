/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:06:14 by mjose             #+#    #+#             */
/*   Updated: 2017/12/16 18:01:14 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	endline_it(char *line_in_buff)
{
	int		count;

	count = 0;
	while (line_in_buff[count] != '\n' && line_in_buff[count])
		count++;
	if (line_in_buff[count] == '\n')
	{
		line_in_buff[count] = '\0';
		return (count);
	}
	else
		return (-1);
}

static char	*stock(char *line_in_buff, char *line_in_file)
{
	size_t	size_lbuff;
	size_t	size_lfile;
	char	*str;

	size_lbuff = 0;
	size_lfile = 0;
	if (line_in_buff)
		size_lbuff = ft_strlen(line_in_buff);
	if (line_in_file)
		size_lfile = ft_strlen(line_in_file);
	str = (char *)malloc(sizeof(*str) * (size_lbuff + size_lfile + 1));
	ft_memcpy(str, line_in_buff, size_lbuff);
	ft_memcpy(str + size_lbuff, line_in_file, size_lfile);
	str[size_lbuff + size_lfile] = '\0';
	free(line_in_buff);
	return (str);
}

static int	line_it(char **line_in_buff, char **line_in_file, char **line)
{
	char	*tmp;
	int		final;

	*line_in_buff = stock(*line_in_buff, *line_in_file);
	final = endline_it(*line_in_buff);
	if (final > -1)
	{
		*line = ft_strdup(*line_in_buff);
		tmp = *line_in_buff;
		*line_in_buff = ft_strdup(*line_in_buff + final + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff[BUFF_SIZE];
	char		*content_file;
	int			rc;

	content_file = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || (read(fd, content_file, 0)) < 0)
		return (-1);
	while ((read(fd, content_file, BUFF_SIZE)) > 0)
	{
		rc = line_it(&buff[fd], &content_file, line);
		free(content_file);
		if (rc == 1)
			return (rc);
		content_file = ft_strnew(BUFF_SIZE);
	}
	if ((rc = line_it(&buff[fd], &content_file, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (rc);
}
