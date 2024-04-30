/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:28:58 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_text_to_im(t_data *d)
{
	int	i;

	d->pokeball_im = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * d->n_pok);
	if (!(d->pokeball_im))
		return (EXIT_FAILURE);
	d->player_im->f = mlx_texture_to_image(d->mlx, d->player_tx->f);
	d->tile_im = mlx_texture_to_image(d->mlx, d->tile_tx);
	d->grass_im = mlx_texture_to_image(d->mlx, d->grass_tx);
	d->stairs_im = mlx_texture_to_image(d->mlx, d->stairs_tx);
	d->charm_im = mlx_texture_to_image(d->mlx, d->charm_tx);
	i = 0;
	while (i < d->n_pok)
	{
		d->pokeball_im[i] = mlx_texture_to_image(d->mlx, d->pokeball_tx);
		i++;
	}
	d->pok_c = 0;
	return (EXIT_SUCCESS);
}

int	set_images_to_game1(t_data *d, int i, int j)
{
	if (d->map[i][j] == '1')
		if (mlx_image_to_window(d->mlx, d->grass_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
	if (d->map[i][j] == '0')
		if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
	if (d->map[i][j] == 'E')
	{
		if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(d->mlx, d->stairs_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
	}
	if (d->map[i][j] == 'C')
	{
		if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(d->mlx, d->pokeball_im[d->pok_c],
				j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
		d->pokeball_loc_i[d->pok_c] = j;
		d->pokeball_loc_j[d->pok_c] = i;
		d->pok_c++;
	}
	return (EXIT_SUCCESS);
}

int	set_images_to_game2(t_data *d, int i, int j)
{
	if (d->map[i][j] == 'P')
	{
		if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(d->mlx, d->player_im->f, j * 16,
				i * 16 - 8) < 0)
			return (EXIT_FAILURE);
		d->i = j;
		d->j = i;
		d->prev_key = MLX_KEY_DOWN;
		d->p_im = d->player_im->f;
	}
	if (d->map[i][j] == 'M')
	{
		if (mlx_image_to_window(d->mlx, d->tile_im, j * 16, i * 16) < 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(d->mlx, d->charm_im, j * 16,
				i * 16 - 4) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	set_images_2(t_data *g_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_data->height)
	{
		j = 0;
		while (j < g_data->width)
		{
			if (set_images_to_game2(g_data, i, j) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	set_images_1(t_data *g_data)
{
	int	i;
	int	j;

	i = 0;
	g_data->pokeball_loc_i = (int *) malloc (sizeof (int) * g_data->n_pok);
	g_data->pokeball_loc_j = (int *) malloc (sizeof (int) * g_data->n_pok);
	if (!(g_data->pokeball_loc_i))
		return (EXIT_FAILURE);
	if (!(g_data->pokeball_loc_j))
		return (EXIT_FAILURE);
	while (i < g_data->height)
	{
		j = 0;
		while (j < g_data->width)
		{
			if (set_images_to_game1(g_data, i, j) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	g_data->pok_c = 0;
	return (EXIT_SUCCESS);
}
