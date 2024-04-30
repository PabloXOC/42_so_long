/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:37 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 16:44:05 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_so_long(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	ft_define_null(data);
	if (ft_readfile(argv[0], data) == EXIT_FAILURE)
	{
		write(2, "Error: Could not read the file.\n", 32);
		ft_free(data);
		return (EXIT_FAILURE);
	}
	if (ft_correct_map(data) == EXIT_FAILURE)
	{
		write(2, "Error: Map given does not follow the rules.\n", 44);
		ft_free(data);
		return (EXIT_FAILURE);
	}
	if (ft_display(data) == EXIT_FAILURE)
	{
		write(2, "Error: Something went wrong making the window.\n", 47);
		ft_free(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc == 1)
	{
		if (ft_so_long(argv) == EXIT_FAILURE)
		{
			return (EXIT_FAILURE);
		}
	}
	else
	{
		write(2, "Error: Wrong number of arguments: expected 1.\n", 46);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* int	main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc == 1)
	{
		if (ft_so_long(argv) == EXIT_FAILURE)
		{
			while (42);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		write(2, "Error: Wrong number of arguments: expected 1.\n", 46);
		while (42);
		return (EXIT_FAILURE);
	}
	while (42);
	return (EXIT_SUCCESS);
} */
