/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:27 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:24:03 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pok_pos(t_data *d)
{
	int	n;

	n = 0;
	while (n < d->n_pok)
	{
		if (d->pokeball_loc_i[n] == d->i && d->pokeball_loc_j[n] == d->j)
		{
			return (n);
		}
		n++;
	}
	return (-1);
}

int	charm2(t_data *d)
{
	int	i;
	int	j;

	i = 1;
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
	return (EXIT_SUCCESS);
}

void	ft_top_row(t_data *g_data)
{
	int	i;

	i = 0;
	while (i < g_data->width)
	{
		mlx_image_to_window(g_data->mlx, g_data->grass_im, i * 16, 0);
		i++;
	}
	charm2(g_data);
}

mlx_texture_t	*ft_find_txtr(t_data *g_data, int keypress)
{
	if (keypress == MLX_KEY_UP)
	{
		return (g_data->player_tx->b);
	}
	else if (keypress == MLX_KEY_DOWN)
	{
		return (g_data->player_tx->f);
	}
	else if (keypress == MLX_KEY_LEFT)
	{
		return (g_data->player_tx->l);
	}
	else
	{
		return (g_data->player_tx->r);
	}
}

void	moves_write(t_data *g_data)
{
	char	*itoa;

	itoa = ft_itoa(0);
	mlx_put_string(g_data->mlx, "Moves: ", 0, -2);
	mlx_put_string(g_data->mlx, itoa, 16 * 4, -2);
	free(itoa);
}
