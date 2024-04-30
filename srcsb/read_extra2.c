/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_extra2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:32:04 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 17:44:28 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_compare_maps(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->n_pok = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if ((data->map[i][j] == 'E' || data->map[i][j] == 'P'
				|| data->map[i][j] == 'C') && map[i][j] != 'F')
				return (EXIT_FAILURE);
			j++;
			if (data->map[i][j] == 'C')
				data->n_pok++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

t_point	ft_find_beg(t_data *data)
{
	int		i;
	int		j;
	t_point	pos;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

void	ft_free_temp_map(char **map, t_point	*begin)
{
	int	i;

	if (map != NULL)
	{
		i = 0;
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	if (begin != NULL)
		free(begin);
}

char	**make_area(char **zone, int x, int y)
{
	char	**new;
	int		i;
	int		j;

	new = (char **) malloc ((y + 1) * sizeof(char *));
	if (!(new))
		return (NULL);
	i = 0;
	while (i < y)
	{
		new[i] = malloc(x + 1);
		if (!(new[i]))
			return (NULL);
		j = 0;
		while (j < x)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][x] = '\0';
		i++;
	}
	new[y] = 0;
	return (new);
}
