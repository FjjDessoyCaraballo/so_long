/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:11:55 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/14 12:11:56 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *msl)
{
	if (msl->map[msl->y_ppos - 1][msl->x_ppos] != '1')
	{
		msl->map[msl->y_ppos][msl->x_ppos] = '0';
		msl->map[msl->y_ppos - 1][msl->x_ppos] = 'P';
		msl->y_ppos -= 1;
		msl->p_move += 1;
		msl->img->img_p->instances->y -= msl->tile_sq;
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'C')
		{
			msl->map[msl->y_ppos][msl->x_ppos] = '0';
			msl->map[msl->y_ppos - 1][msl->x_ppos] = 'P';
			msl->y_ppos -= 1;
			msl->p_move += 1;
			mlx_delete_image(msl->mlx, msl->img->img_c);
			mlx_image_to_window(msl->mlx, msl->img->img_0, msl->x * msl->tile_sq,
						(msl->y - 1) * msl->tile_sq);
			ft_printf("find C\n");
			msl->img->img_p->instances->y -= msl->tile_sq;
		}
	}

}

void	move_left(t_map *msl)
{
	if (msl->map[msl->y_ppos][msl->x_ppos - 1] != '1')
	{
		msl->map[msl->y_ppos][msl->x_ppos] = '0';
		msl->map[msl->y_ppos][msl->x_ppos - 1] = 'P';
		msl->x_ppos -= 1;
		msl->p_move += 1;
		msl->img->img_p->instances->x -= msl->tile_sq;
	}
}

void	move_down(t_map *msl)
{
	if (msl->map[msl->y_ppos + 1][msl->x_ppos] != '1')
	{
		msl->map[msl->y_ppos][msl->x_ppos] = '0';
		msl->map[msl->y_ppos + 1][msl->x_ppos] = 'P';
		msl->y_ppos += 1;
		msl->p_move += 1;
		msl->img->img_p->instances->y += msl->tile_sq;
	}
}

void	move_right(t_map *msl)
{
	if (msl->map[msl->y_ppos][msl->x_ppos + 1] != '1')
	{
		msl->map[msl->y_ppos][msl->x_ppos] = '0';
		msl->map[msl->y_ppos][msl->x_ppos + 1] = 'P';
		msl->x_ppos += 1;
		msl->p_move += 1;
		msl->img->img_p->instances->x += msl->tile_sq;
	}
}

// void	move_left(t_map *msl)
// {
// 	if (msl->map[msl->y_ppos ][msl->x_ppos - 1] == '0')
// 	{
// 		msl->map[msl->y_ppos][msl->x_ppos] = '0';
// 		msl->map[msl->y_ppos][msl->x_ppos - 1] = 'P';
// 		msl->x_ppos -= 1;
// 		msl->img->img_p->instances->x -= msl->tile_sq;
// 	}
// 	else if (msl->map[msl->y_ppos][msl->x_ppos - 1] == 'C')
// 	{
// 		msl->map[msl->y_ppos][msl->x_ppos] = '0';
// 		msl->map[msl->y_ppos][msl->x_ppos - 1] = 'P';
// 		msl->x_ppos -= 1;
// 		msl->img->img_p->instances->x -= msl->tile_sq;
// 		msl->collect--;
// 		if (msl->collect == 0)
// 			msl->map[msl->y_epos][msl->x_epos] = 'E';
// 	}
// 	else if (msl->map[msl->y_ppos][msl->x_ppos - 1] == 'E')
// 	{
// 		msl->x_ppos -= 1;
// 		msl->img->img_p->instances->x -= msl->tile_sq;
// 	}
// }