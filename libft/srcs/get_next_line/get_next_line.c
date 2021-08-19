/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:40:41 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:05:24 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_endline(char *buffer, char *chest, int param)
{
	int	end;
	int	i;
	int	j;

	end = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (param == GNL_COPY && end != 0)
		{
			chest[j] = buffer[i];
			j++;
		}
		if (end == 0 && buffer[i] == '\n')
		{
			end = 1;
			buffer[i] = '\0';
		}
		i++;
	}
	return (end);
}

static int	gnl_clean(int code, char **line, char **chest, int fd)
{
	if (code <= 0)
	{
		if (chest[fd] != NULL)
		{
			free(chest[fd]);
			chest[fd] = NULL;
		}
	}
	if (code == -1)
	{
		if (*line != NULL)
		{
			free(*line);
			*line = NULL;
		}
	}
	return (code);
}

static int	check_chest(int fd, char **chest, char **line)
{
	int	line_read;
	int	i;

	line_read = 0;
	if (chest[fd] == NULL)
	{
		chest[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (chest[fd] == NULL)
			return (gnl_clean(-1, line, chest, fd));
	}
	else
	{
		i = 0;
		line_read = check_endline(chest[fd], chest[fd], GNL_NOCOPY);
		while (chest[fd][i++] != '\0')
			;
		if (ft_gnljoin(line, chest[fd]) == -1)
			return (gnl_clean(-1, line, chest, fd));
		ft_strlcpy(chest[fd], &chest[fd][i], BUFFER_SIZE);
	}
	if (line_read == 0)
		ft_bzero(chest[fd], sizeof(char) * (BUFFER_SIZE + 1));
	return (line_read);
}

static int	get_line(int fd, char **chest, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		end;
	int		read_size;

	end = 0;
	read_size = 0;
	while (end == 0)
	{
		ft_bzero(buffer, sizeof(char) * (BUFFER_SIZE + 1));
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (gnl_clean(read_size, line, chest, fd));
		end = check_endline(buffer, chest[fd], GNL_COPY);
		if (ft_gnljoin(line, buffer) == -1)
			return (gnl_clean(-1, line, chest, fd));
		else if (end == 0 && read_size < BUFFER_SIZE)
			return (gnl_clean(0, line, chest, fd));
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*chest[FD_MAX];
	int			valid_fd;
	int			code;
	int			line_read;

	line_read = 0;
	code = 0;
	valid_fd = 0;
	if ((fd < 0 || fd >= FD_MAX) || !line || BUFFER_SIZE <= 0)
		return (-1);
	valid_fd = read(fd, line, 0);
	if (valid_fd == -1)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	if (line == NULL)
		return (gnl_clean(-1, line, chest, fd));
	ft_bzero(*line, sizeof(char));
	line_read = check_chest(fd, chest, line);
	if (line_read != 0)
		return (gnl_clean(line_read, line, chest, fd));
	code = get_line(fd, chest, line);
	return (code);
}
