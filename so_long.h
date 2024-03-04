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
# define ERR_MAP "Error: Invalid map"

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
void	so_long(t_map map_struct, char **argv);

/* arg_input.c */
void	invalid_arg(int argc, char **argv);

/* map_handling.c */
void	parse_map(t_map map_struct, char *fname);
size_t	count_lines(int fd);
void	validate_map(t_map map_struct);

/* map_validation.c */
void	check_rectangle(t_map map_struct);

/* utils.c */
size_t	ft_strlen_mod(const char *s);
void	remove_nl(t_map map_struct);

#endif



