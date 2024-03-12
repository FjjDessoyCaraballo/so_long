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

	texture_loading(mlx, isl);
	resize_image(msl, isl);
	// msl->img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	msl->x = 0;
	msl->y = 0;
	mlx_image_to_window(mlx, msl->img->img_bg, 0, 0);
	map_allocation(msl, mlx);
}


void	texture_loading(mlx_t *mlx, t_img *isl)
{
	isl->txt_bg = mlx_load_png("./sprites/bg.png");
	isl->txt_1 = mlx_load_png("./sprites/one.png");
	isl->txt_0 = mlx_load_png("./sprites/zero.png");
	isl->txt_p = mlx_load_png("./sprites/P.png");
	isl->txt_c = mlx_load_png("./sprites/C.png");
	isl->txt_e = mlx_load_png("./sprites/E.png");
	isl->img_bg = mlx_texture_to_image(mlx, isl->txt_bg);
	isl->img_1 = mlx_texture_to_image(mlx, isl->txt_1);
	isl->img_0 = mlx_texture_to_image(mlx, isl->txt_0);
	isl->img_p = mlx_texture_to_image(mlx, isl->txt_p);
	isl->img_c = mlx_texture_to_image(mlx, isl->txt_c);
	isl->img_e = mlx_texture_to_image(mlx, isl->txt_e);

}
void	resize_image(t_map *msl, t_img *isl)
{
	mlx_resize_image(isl->img_1, msl->tile_w, msl->tile_h);
	mlx_resize_image(isl->img_0, msl->tile_w, msl->tile_h);
	mlx_resize_image(isl->img_p, msl->tile_w, msl->tile_h);
	mlx_resize_image(isl->img_c, msl->tile_w, msl->tile_h);
	mlx_resize_image(isl->img_e, msl->tile_w, msl->tile_h);
	mlx_resize_image(isl->img_bg, WINDOW_W, WINDOW_H);
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

void	map_allocation(t_map *msl, mlx_t *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (msl->map[i])
	{
		j = 0;
		msl->x = 0;
		while (msl->map[i][j])
		{
			if (msl->map[i][j] == '0')
				mlx_image_to_window(mlx, msl->img->img_0, msl->x * msl->tile_sq, msl->y * msl->tile_sq);
			else if (msl->map[i][j] == 'P')
				mlx_image_to_window(mlx, msl->img->img_p, msl->x * msl->tile_sq, msl->y * msl->tile_sq);
			else if (msl->map[i][j] == 'E')
				mlx_image_to_window(mlx, msl->img->img_e, msl->x * msl->tile_sq, msl->y * msl->tile_sq);
			else if (msl->map[i][j] == 'C')
				mlx_image_to_window(mlx, msl->img->img_c, msl->x * msl->tile_sq, msl->y * msl->tile_sq);
			else
				mlx_image_to_window(mlx, msl->img->img_1, msl->x * msl->tile_sq, msl->y * msl->tile_sq);
			j++;
			msl->x++;
		}
		i++;
		msl->y++;
	}
} 
