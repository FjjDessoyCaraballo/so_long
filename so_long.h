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
# include "libft/includes/libft.h"

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
# define ERR_ARG "Invalid number of arguments"
# define ERR_FILE "No valid .ber file inserted"
# define MAP_FD "Error reading the map"

/* game record macros */
// # define heigh
// # define width

/* map struct */
typedef struct s_map
{
	// char **map;
	char *temp_map;
}				t_map;

/* so_long.c */
void	so_long(t_map map_struct, char **argv);

/* arg_input.c */
void	invalid_arg(int argc, char **argv);

/* map_handling.c */
void	take_map(t_map map_struct, char **argv);
void	parse_map(t_map map_struct, int fd);

/* utils.c */
void	free_array(char **array);

#endif



