/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 14:10:04 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_null(t_data *data)
{
	data->tile_im = NULL;
	data->tile_tx = NULL;
	data->player_im = NULL;
	data->player_tx = NULL;
	data->map = NULL;
	data->mapline = NULL;
	data->n_moves = 0;
}

void	ft_free_player(t_data *data)
{
	if (data->player_tx != NULL)
	{
		if ((int) data->player_tx->b != 0)
			free(data->player_tx->b);
		if ((int) data->player_tx->f != 0)
			free(data->player_tx->f);
		if ((int) data->player_tx->l != 0)
			free(data->player_tx->l);
		if ((int) data->player_tx->r != 0)
			free(data->player_tx->r);
		free(data->player_tx);
	}
	if (data->player_im != NULL)
	{
		if (data->player_im->b != 0)
			free(data->player_im->b);
		if (data->player_im->f != 0)
			free(data->player_im->f);
		if (data->player_im->l != 0)
			free(data->player_im->l);
		if (data->player_im->r != 0)
			free(data->player_im->r);
		free(data->player_im);
	}
}

void	ft_free_map(t_data	*data)
{
	int	i;

	if (data->map != NULL)
	{
		i = 0;
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	ft_free(t_data *data)
{
	if (data->grass_im != NULL)
		free(data->grass_im);
	if (data->grass_tx != NULL)
		free(data->grass_tx);
	if (data->tile_im != NULL)
		free(data->tile_im);
	if (data->tile_tx != NULL)
		free(data->tile_tx);
	if (data->mapline != NULL)
		free(data->mapline);
	if (data->pokeball_tx != NULL)
		free(data->pokeball_tx);
	if (data->pokeball_im != NULL)
		free(data->pokeball_im);
	if (data->stairs_tx != NULL)
		free(data->stairs_tx);
	if (data->stairs_im != NULL)
		free(data->stairs_im);
	if (data->p_im != NULL)
		free(data->p_im);
	ft_free_player(data);
	ft_free_map(data);
	free(data);
}
