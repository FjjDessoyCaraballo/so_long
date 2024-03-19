/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:48:06 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/02 13:48:07 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_map *msl, char **argv, mlx_t *mlx, t_img *isl)
{
	parse_map(msl, argv[1]);
	tile_size(msl);
	mlx = mlx_init(msl->width * msl->tile_sq, msl->height * msl->tile_sq,
			"so_long", true);
	if (!mlx)
	{
		free_array(msl->map);
		exit(1);
	}
	msl->mlx = mlx;
	img_init(msl, mlx, isl);
	msl->p_move = 1;
	player_controls(msl, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
