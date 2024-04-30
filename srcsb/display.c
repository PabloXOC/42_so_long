/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:24:13 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize_window(int32_t width, int32_t height, void *param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		key_press(keydata.key, data);
}

void	ft_zeros_tx(t_data *data)
{
	data->player_tx->b = 0;
	data->player_tx->f = 0;
	data->player_tx->l = 0;
	data->player_tx->r = 0;
}

void	ft_zeros_im(t_data *data)
{
	data->player_im->b = 0;
	data->player_im->f = 0;
	data->player_im->l = 0;
	data->player_im->r = 0;
}

int	ft_display(t_data *data)
{
	data->mlx = mlx_init(data->width * 16, data->height * 16, "MLX42", TRUE);
	if (!data->mlx)
		return (EXIT_FAILURE);
	data->player_tx = (t_player_tx *) malloc (sizeof (t_player_tx));
	if (!(data->player_tx))
		return (EXIT_FAILURE);
	ft_zeros_tx(data);
	if (ft_load(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_load_char(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->player_im = (t_player_im *) malloc (sizeof (t_player_im));
	if (!(data->player_im))
		return (EXIT_FAILURE);
	ft_zeros_im(data);
	ft_text_to_im(data);
	if (!data->player_im->f)
		return (EXIT_FAILURE);
	set_images_1(data);
	set_images_2(data);
	moves_write(data);
	mlx_key_hook(data->mlx, &key_hook, data);
	mlx_resize_hook(data->mlx, &resize_window, NULL);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
