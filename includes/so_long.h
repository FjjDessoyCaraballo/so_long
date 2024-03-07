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
// /* MLX42 */
// # include "MLX42/MLX42.h" // not ready yet

/* error macros */
# define ERR_ARG "Error: invalid number of arguments\n"
# define ERR_FILE "Error: no valid .ber file inserted\n"
# define MAP_FD "Error: failed to read the map\n"
# define ERR_MAP "Error: invalid map size\n"
# define ERR_CHAR "Error: invalid map content\n"
# define ERR_WALL "Error: map must be closed by walls\n"
# define ERR_PATH "Error: player does not have a valid path\n"

/* game record macros */
// # define heigh
// # define width

/* map struct */
typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	collect;
	size_t	x_ppos;
	size_t	y_ppos;
}				t_map;

/* so_long.c */
void	so_long(t_map *msl, char **argv);

/* arg_input.c */
void	invalid_arg(int argc, char **argv);

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

#endif
