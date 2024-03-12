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
	ft_printf("tilesq:%d\n", msl->tile_sq);
	mlx = mlx_init(msl->width * msl->tile_sq, msl->height * msl->tile_sq, "so_long", true);
	img_init(msl, mlx, isl);
	msl->mlx = mlx;
	if (!mlx)
	{
		free_array(msl->map);
		exit(1);
	}
	mlx_loop(mlx);
	// mlx_close_window(mlx);
}

	/*
	png to texture
	texture to image
	image to window
	
	dont forget to credit jobromedia @
	https://opengameart.org/content/7x4-font*/

