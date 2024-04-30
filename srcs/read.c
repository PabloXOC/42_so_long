/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:56:17 by pximenez          #+#    #+#             */
/*   Updated: 2024/03/20 17:34:30 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_filesize(char *filename, int filesize)
{
	int		fd;
	char	buffer[4096];
	int		bytesread;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytesread = read(fd, buffer, sizeof(buffer));
	while (bytesread > 0)
	{
		filesize += bytesread;
		bytesread = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	if (bytesread == -1)
		return (-1);
	return (filesize);
}

char	*ft_readfile2(int fd, int filesize, int bytesread)
{
	int		offset;
	char	*filecontent;

	filecontent = (char *) malloc (filesize + 1);
	if (filecontent == (NULL))
		return (NULL);
	offset = 0;
	bytesread = read(fd, filecontent + offset, filesize - offset);
	while (bytesread > 0)
	{
		offset += bytesread;
		bytesread = read(fd, filecontent + offset, filesize - offset);
	}
	if (bytesread == -1)
	{
		free(filecontent);
		return (NULL);
	}
	filecontent[filesize] = '\0';
	return (filecontent);
}

int	ft_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_readfile(char *filename, t_data *data)
{
	int		fd;
	int		filesize;
	char	*filecontent;

	if (ft_extension(filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	filesize = ft_filesize(filename, 0);
	if (filesize == -1)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	filecontent = ft_readfile2(fd, filesize, 0);
	close(fd);
	data->mapline = filecontent;
	return (EXIT_SUCCESS);
}
