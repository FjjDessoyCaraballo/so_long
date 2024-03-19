/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:43:39 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/11 14:43:40 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_map *msl, mlx_t *mlx, t_img *isl)
{
	texture_loading(mlx, msl, isl);
	resize_image(msl, isl);
	if (mlx_image_to_window(mlx, msl->img->img_bg, 0, 0) < 0)
		end_game(msl, 1);
	map_allocations(msl, mlx);
}

void	texture_loading(mlx_t *mlx, t_map *msl, t_img *isl)
{
	isl->txt_bg = mlx_load_png("./sprites/bg.png");
	isl->txt_1 = mlx_load_png("./sprites/one.png");
	isl->txt_0 = mlx_load_png("./sprites/zero.png");
	isl->txt_p = mlx_load_png("./sprites/P.png");
	isl->txt_c = mlx_load_png("./sprites/C.png");
	isl->txt_e = mlx_load_png("./sprites/E.png");
	if (!isl->txt_1 || !isl->txt_0 || !isl->txt_p
		|| !isl->txt_c || !isl->txt_bg || !isl->txt_e)
		end_game(msl, 1);
	isl->img_bg = mlx_texture_to_image(mlx, isl->txt_bg);
	isl->img_1 = mlx_texture_to_image(mlx, isl->txt_1);
	isl->img_0 = mlx_texture_to_image(mlx, isl->txt_0);
	isl->img_p = mlx_texture_to_image(mlx, isl->txt_p);
	isl->img_c = mlx_texture_to_image(mlx, isl->txt_c);
	isl->img_e = mlx_texture_to_image(mlx, isl->txt_e);
	if (!isl->img_0 || !isl->img_1 || !isl->img_bg
		|| !isl->img_c || !isl->img_e || !isl->img_p)
		end_game(msl, 1);
}

void	resize_image(t_map *msl, t_img *isl)
{
	if (!mlx_resize_image(isl->img_1, msl->tile_sq, msl->tile_sq))
		end_game(msl, 1);
	if (!mlx_resize_image(isl->img_0, msl->tile_sq, msl->tile_sq))
		end_game(msl, 1);
	if (!mlx_resize_image(isl->img_p, msl->tile_sq, msl->tile_sq))
		end_game(msl, 1);
	if (!mlx_resize_image(isl->img_c, msl->tile_sq, msl->tile_sq))
		end_game(msl, 1);
	if (!mlx_resize_image(isl->img_e, msl->tile_sq, msl->tile_sq))
		end_game(msl, 1);
	if (!mlx_resize_image(isl->img_bg, WINDOW_W, WINDOW_H))
		end_game(msl, 1);
}

void	tile_size(t_map *msl)
{
	msl->tile_w = WINDOW_W / msl->width;
	msl->tile_h = WINDOW_H / msl->height;
	if (msl->tile_w <= msl->tile_h)
		msl->tile_sq = msl->tile_w;
	else
		msl->tile_sq = msl->tile_h;
	msl->moves = 0;
}

void	map_allocations(t_map *msl, mlx_t *mlx)
{
	map_allocation_0(msl, mlx);
	map_allocation_1(msl, mlx);
	map_allocation_c(msl, mlx);
	map_allocation_e(msl, mlx);
	map_allocation_p(msl, mlx);
}
