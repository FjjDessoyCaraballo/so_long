/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:48:31 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/02 13:48:33 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* MLX42 */
# include "./MLX42/MLX42.h"
/* libft */
# include "libft.h"

/* permitted libraries */
/* for close, read, write, unlink, dup, dup2, execve, fork, pipe, access */
# include <unistd.h>

/* for open, */
# include <fcntl.h>

/* for malloc, free, exit */
# include <stdlib.h>

/* for perror */
# include <stdio.h>

/* error macros */
# define ERR_ARG "Error\nInvalid number of arguments\n"
# define ERR_DIR "Error\n"
# define ERR_FILE "Error\nNo valid .ber file inserted\n"
# define MAP_FD "Error\nFailed to read the map\n"
# define ERR_MAP "Error\nInvalid map size\n"
# define ERR_CHAR "Error\nInvalid map content\n"
# define ERR_WALL "Erro\nMap must be closed by walls\n"
# define ERR_PATH "Error\nPlayer does not have a valid path\n"

/* window size */
# define WINDOW_W 1366
# define WINDOW_H 768

/* textures and images struct */
typedef struct s_img
{
	mlx_texture_t	*txt_0;
	mlx_texture_t	*txt_1;
	mlx_texture_t	*txt_c;
	mlx_texture_t	*txt_p;
	mlx_texture_t	*txt_e;
	mlx_texture_t	*txt_bg;
	mlx_image_t		*img_0;
	mlx_image_t		*img_1;
	mlx_image_t		*img_c;
	mlx_image_t		*img_p;
	mlx_image_t		*img_e;
	mlx_image_t		*img_bg;
}				t_img;

/* map struct */
typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	collect;
	size_t	x_ppos;
	size_t	y_ppos;
	size_t	tile_w;
	size_t	tile_h;
	size_t	tile_sq;
	size_t	moves;
	size_t	x;
	size_t	y;
	mlx_t	*mlx;
	t_img	*img;
}				t_map;

/* so_long.c */
void	so_long(t_map *msl, char **argv, mlx_t *mlx, t_img *isl);

/* arg_input.c */
void	invalid_arg(int argc, char **argv);
void	is_dir(char *dir);

/* map_handling.c */
void	parse_map(t_map *msl, char *fname);
void	validate_map(t_map *msl, char **map_cpy);

/* map_validation.c */
void	check_rectangle(t_map *msl);
void	check_character(t_map *msl);
void	check_walls(t_map *msl);
void	check_content(t_map *msl);
void	content_found(t_map *msl, size_t found);

/* walls.c */
void	check_upper_wall(t_map *msl);
void	check_lower_wall(t_map *msl);
void	check_left_wall(t_map *msl);
void	check_right_wall(t_map *msl);

/* utils.c */
void	remove_nl(t_map *msl);
size_t	count_lines(int fd);
char	**copy_map(char **map, size_t row, size_t column);
void	exit_all(char **map1, char **map2);

/* contents.c */
size_t	count_collect(t_map *msl);

/* flood_fill.c */
void	flood_fill(char **map, size_t y, size_t x);
void	check_fill_exit(t_map *msl, char **map_cpy);

/* draw_map.c */
void	img_init(t_map *msl, mlx_t *mlx, t_img *isl);
void	texture_loading(mlx_t *mlx, t_img *isl);
void	resize_image(t_map *msl, t_img *isl);
void	tile_size(t_map *msl);
void	map_allocation(t_map *msl, mlx_t *mlx);

#endif
