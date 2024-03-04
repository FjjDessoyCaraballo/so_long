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
# define ERR_ARG "Error: invalid number of arguments"
# define ERR_FILE "Error: no valid .ber file inserted"
# define MAP_FD "Error: failed to read the map"
# define ERR_MAP "Error: invalid map size"
# define ERR_CHAR "Error: invalid map content"
# define ERR_WALL "Error: map must be closed by walls"

/* game record macros */
// # define heigh
// # define width

/* map struct */
typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
}				t_map;

/* so_long.c */
void	so_long(t_map msl, char **argv);

/* arg_input.c */
void	invalid_arg(int argc, char **argv);

/* map_handling.c */
void	parse_map(t_map msl, char *fname);
size_t	count_lines(int fd);
void	validate_map(t_map msl);

/* map_validation.c */
void	check_rectangle(t_map msl);
void	check_character(char **map);
void	check_walls(t_map msl);

/* walls.c */
void	check_upper_wall(t_map msl);
void	check_lower_wall(t_map msl);
void	check_left_wall(t_map msl);
void	check_right_wall(t_map msl);

/* utils.c */
size_t	ft_strlen_mod(const char *s);
void	remove_nl(t_map msl);

#endif
