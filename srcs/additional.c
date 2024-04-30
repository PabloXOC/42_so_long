/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:27 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 12:58:10 by pximenez         ###   ########.fr       */
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
