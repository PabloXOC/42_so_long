/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:31:37 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_move(t_data *d, int x, int y, int keypress)
{
	char	*itoa;

	ft_top_row(d);
	mlx_delete_image(d->mlx, d->p_im);
	d->p_im = mlx_texture_to_image(d->mlx, ft_find_txtr(d, keypress));
	d->i += x;
	d->j += y;
	d->n_moves++;
	mlx_image_to_window(d->mlx, d->p_im, d->i * 16, d->j * 16 - 8);
	mlx_put_string(d->mlx, "Moves: ", 0, -2);
	itoa = ft_itoa(d->n_moves);
	mlx_put_string(d->mlx, itoa, 16 * 4, -2);
	ft_charmander(d);
	free(itoa);
}

void	ft_key_rot1(t_data *d, int keypress)
{
	if (keypress == (int) MLX_KEY_UP)
	{
		d->prev_key = (int) MLX_KEY_UP;
		d->player_im->b = mlx_texture_to_image(d->mlx, d->player_tx->b);
		mlx_image_to_window(d->mlx, d->player_im->b, d->i * 16, d->j * 16 - 8);
		mlx_delete_image(d->mlx, d->p_im);
		d->p_im = d->player_im->b;
	}
	if (keypress == (int) MLX_KEY_DOWN)
	{
		d->prev_key = (int) MLX_KEY_DOWN;
		d->player_im->f = mlx_texture_to_image(d->mlx, d->player_tx->f);
		mlx_image_to_window(d->mlx, d->player_im->f, d->i * 16, d->j * 16 - 8);
		mlx_delete_image(d->mlx, d->p_im);
		d->p_im = d->player_im->f;
	}
}

void	ft_key_rot2(t_data *d, int keypress)
{
	if (keypress == (int) MLX_KEY_LEFT)
	{
		d->prev_key = keypress;
		d->player_im->l = mlx_texture_to_image(d->mlx, d->player_tx->l);
		mlx_image_to_window(d->mlx, d->player_im->l, d->i * 16, d->j * 16 - 8);
		mlx_delete_image(d->mlx, d->p_im);
		d->p_im = d->player_im->l;
	}
	if (keypress == (int) MLX_KEY_RIGHT)
	{
		d->prev_key = keypress;
		d->player_im->r = mlx_texture_to_image(d->mlx, d->player_tx->r);
		mlx_image_to_window(d->mlx, d->player_im->r, d->i * 16, d->j * 16 - 8);
		mlx_delete_image(d->mlx, d->p_im);
		d->p_im = d->player_im->r;
	}
}

void	key_press2(int keypress, t_data *d)
{
	char	*itoa;

	ft_top_row(d);
	ft_key_rot1(d, keypress);
	ft_key_rot2(d, keypress);
	mlx_put_string(d->mlx, "Moves: ", 0, -2);
	itoa = ft_itoa(d->n_moves);
	mlx_put_string(d->mlx, itoa, 16 * 4, -2);
	ft_charmander(d);
	free(itoa);
}

void	key_press(int keypress, t_data *d)
{
	if (keypress == d->prev_key)
	{
		if (keypress == (int) MLX_KEY_UP && d->map[d->j - 1][d->i] != '1')
			ft_key_move(d, 0, -1, keypress);
		if (keypress == (int) MLX_KEY_DOWN && d->map[d->j + 1][d->i] != '1')
			ft_key_move(d, 0, 1, keypress);
		if (keypress == (int) MLX_KEY_LEFT && d->map[d->j][d->i - 1] != '1')
			ft_key_move(d, -1, 0, keypress);
		if (keypress == (int) MLX_KEY_RIGHT && d->map[d->j][d->i + 1] != '1')
			ft_key_move(d, 1, 0, keypress);
		if (d->map[d->j][d->i] == 'C')
		{
			mlx_delete_image(d->mlx, d->pokeball_im[pok_pos(d)]);
			d->pok_c++;
			d->map[d->j][d->i] = 'N';
		}
		if (d->map[d->j][d->i] == 'M')
			mlx_close_window(d->mlx);
		if (d->map[d->j][d->i] == 'E' && d->pok_c == d->n_pok)
			mlx_close_window(d->mlx);
	}
	else
		key_press2(keypress, d);
}
