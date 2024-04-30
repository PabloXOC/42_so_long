/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 14:10:16 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P'
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

int	ft_access2(t_data *data, t_point *begin, char **map)
{
	if (begin->x == -1 || begin->y == -1)
	{
		ft_free_temp_map(map, begin);
		return (EXIT_FAILURE);
	}
	fill(map, (t_point){data->width, data->height}, *begin);
	if (ft_compare_maps(data, map) == EXIT_FAILURE)
	{
		ft_free_temp_map(map, begin);
		return (EXIT_FAILURE);
	}
	ft_free_temp_map(map, begin);
	return (EXIT_SUCCESS);
}

int	ft_access(t_data *data)
{
	char	**map;
	t_point	*begin;

	map = make_area(data->map, data->width, data->height);
	if (map == NULL)
	{
		begin = NULL;
		ft_free_temp_map(map, begin);
		return (EXIT_FAILURE);
	}
	begin = (t_point *) malloc (sizeof(t_point));
	if (begin == NULL)
	{
		ft_free_temp_map(map, begin);
		return (EXIT_FAILURE);
	}
	*begin = ft_find_beg(data);
	if (ft_access2(data, begin, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_correct_map(t_data *data)
{
	ft_width_calc(data, 0, 0);
	ft_height_calc(data);
	if (data->height < 3 || data->width < 3 || data->width == data->height)
		return (EXIT_FAILURE);
	if (ft_make_map(data, 0, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_borders(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_char_count(data, 'C') == 0 || ft_char_count(data, 'P') != 1
		|| ft_char_count(data, 'E') != 1)
		return (EXIT_FAILURE);
	if (ft_access(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
