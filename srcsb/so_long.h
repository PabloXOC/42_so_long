/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pximenez <pximenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:14:43 by pximenez          #+#    #+#             */
/*   Updated: 2024/04/10 18:33:27 by pximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*-------INCLUDES-------*/
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct player_tx
{
	mlx_texture_t	*f;
	mlx_texture_t	*l;
	mlx_texture_t	*r;
	mlx_texture_t	*b;
}					t_player_tx;

typedef struct player_im
{
	mlx_image_t	*f;
	mlx_image_t	*l;
	mlx_image_t	*r;
	mlx_image_t	*b;
}				t_player_im;

typedef struct data
{
	char			*mapline;
	char			**map;
	void			*mlx_win;
	mlx_t			*mlx;
	t_player_tx		*player_tx;
	t_player_im		*player_im;
	mlx_texture_t	*tile_tx;
	mlx_image_t		*tile_im;
	mlx_texture_t	*charm_tx;
	mlx_image_t		*charm_im;
	mlx_texture_t	*grass_tx;
	mlx_image_t		*grass_im;
	mlx_texture_t	*stairs_tx;
	mlx_image_t		*stairs_im;
	mlx_texture_t	*pokeball_tx;
	mlx_image_t		**pokeball_im;
	int				*pokeball_loc_i;
	int				*pokeball_loc_j;
	int				n_pok;
	int				pok_c;
	mlx_image_t		*p_im;
	int				height;
	int				width;
	int				prev_key;
	int				i;
	int				j;
	int				n_moves;
}					t_data;

/*------PROTOYPES-------*/
int				main(int argc, char **argv);
int				ft_so_long(char **argv);

//so_long_extra
void			ft_define_null(t_data *data);
void			ft_free(t_data *data);
void			ft_free2(t_data *data);
void			ft_free_map(t_data	*data);
void			ft_free_player(t_data *data);

//read
int				ft_readfile(char *filename, t_data *data);
int				ft_filesize(char *filename, int filesize);
char			*ft_readfile2(int fd, int filesize, int bytesread);
int				ft_extension(char *filename);

//correct_map
int				ft_correct_map(t_data *data);
int				ft_access(t_data *data);
int				ft_access2(t_data *data, t_point *begin, char **map);
void			fill(char **tab, t_point size, t_point cur);

//read_exta1
int				ft_char_count(t_data *data, char c);
void			ft_width_calc(t_data *data, int length, int i);
void			ft_height_calc(t_data *data);
int				ft_make_map(t_data *data, int i, int j);
int				ft_borders(t_data *data);

//read_extra2
char			**make_area(char **zone, int x, int y);
void			ft_free_temp_map(char **map, t_point	*begin);
t_point			ft_find_beg(t_data *data);
int				ft_compare_maps(t_data *data, char **map);

//images
int				ft_text_to_im(t_data *d);
int				set_images_to_game1(t_data *d, int i, int j);
int				set_images_to_game2(t_data *d, int i, int j);
int				set_images_1(t_data *g_data);
int				set_images_2(t_data *g_data);

//images2
int				ft_load(t_data *data);
int				ft_load_char(t_data *data);
int				ft_charmander(t_data *d);
//ft_charmander belongs to keys

//keys
void			ft_key_move(t_data *d, int x, int y, int keypress);
void			ft_key_rot1(t_data *d, int keypress);
void			ft_key_rot2(t_data *d, int keypress);
void			key_press2(int keypress, t_data *d);
void			key_press(int keypress, t_data *d);

//display
void			resize_window(int32_t width, int32_t height, void *param);
void			key_hook(mlx_key_data_t keydata, void *param);
void			ft_zeros_tx(t_data *data);
void			ft_zeros_im(t_data *data);
int				ft_display(t_data *data);

//additional
int				pok_pos(t_data *d);
void			ft_top_row(t_data *g_data);
mlx_texture_t	*ft_find_txtr(t_data *g_data, int keypress);
void			moves_write(t_data *g_data);
int				ft_load_char(t_data *data);

#endif