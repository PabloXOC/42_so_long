/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:31:05 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load(t_data *data)
{
	data->player_tx->f = mlx_load_png("./sprites/character/front.png");
	if (data->player_tx->f == 0)
		return (EXIT_FAILURE);
	data->player_tx->l = mlx_load_png("./sprites/character/left.png");
	if (data->player_tx->l == 0)
		return (EXIT_FAILURE);
	data->player_tx->b = mlx_load_png("./sprites/character/back.png");
	if (data->player_tx->b == 0)
		return (EXIT_FAILURE);
	data->player_tx->r = mlx_load_png("./sprites/character/right.png");
	if (data->player_tx->r == 0)
		return (EXIT_FAILURE);
	data->tile_tx = mlx_load_png("./sprites/path.png");
	if (data->tile_tx == 0)
		return (EXIT_FAILURE);
	data->grass_tx = mlx_load_png("./sprites/grass.png");
	if (data->grass_tx == 0)
		return (EXIT_FAILURE);
	data->stairs_tx = mlx_load_png("./sprites/stairs.png");
	if (data->stairs_tx == 0)
		return (EXIT_FAILURE);
	data->pokeball_tx = mlx_load_png("./sprites/pokeball.png");
	if (data->pokeball_tx == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_load_char(t_data *data)
{
	data->charm_tx = mlx_load_png("./sprites/charmander.png");
	if (data->charm_tx == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_charmander(t_data *d)
{
	int	i;
	int	j;

	i = d->j;
	while (i < d->height)
	{
		j = 0;
		while (j < d->width)
		{
			if (d->map[i][j] == 'M')
			{
				if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
					return (EXIT_FAILURE);
				if (mlx_image_to_window(d->mlx, d->charm_im, j * 16,
						i * 16 - 4) < 0)
					return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
