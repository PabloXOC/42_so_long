/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_extra1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:07:22 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 17:27:08 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_width_calc(t_data *data, int length, int i)
{
	int	prev;

	while (data->mapline[i] != 0)
	{
		prev = length;
		length = 0;
		while (data->mapline[i] != '\n' && data->mapline[i] != 0)
		{
			length++;
			i++;
		}
		if (prev != length && prev != 0)
		{
			data->width = -1;
			return ;
		}
		if (data->mapline[i] != 0)
			i++;
	}
	data->width = length;
}

void	ft_height_calc(t_data *data)
{
	int	i;
	int	height;

	i = 0;
	height = 1;
	while (data->mapline[i] != 0)
	{
		if (data->mapline[i] == '\n')
			height++;
		i++;
	}
	data->height = height;
}

int	ft_make_map(t_data *data, int i, int j)
{
	int	k;

	data->map = (char **) malloc ((data->height + 1) * sizeof(char *));
	if (data->map == NULL)
		return (EXIT_FAILURE);
	while (j < data->height)
	{
		data->map[j] = (char *) malloc ((data->width + 1) * sizeof(char));
		if (data->map == NULL)
			return (EXIT_FAILURE);
		k = 0;
		while (k < data->width)
		{
			data->map[j][k] = data->mapline[i];
			k++;
			i++;
		}
		data->map[j][data->width] = 0;
		j++;
		i++;
	}
	data->map[data->height] = 0;
	return (EXIT_SUCCESS);
}

int	ft_borders(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != '1' && (i == 0 || i == data->height - 1
				|| j == 0 || j == data->width - 1))
				return (EXIT_FAILURE);
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'C')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_char_count(t_data *data, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->mapline[i] != 0)
	{
		if (data->mapline[i] == c)
			count++;
		i++;
	}
	return (count);
}
