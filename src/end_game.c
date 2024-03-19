/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:06:35 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/18 15:06:36 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 0 for sucessful endgame */
/* 1 for failed endgame    */
void	end_game(t_map *msl, int num)
{
	if (num == 0)
	{
		ft_putstr_fd(WIN1, 1);
		ft_putstr_fd(WIN2, 1);
		ft_putstr_fd(WIN3, 1);
		ft_putstr_fd(WIN4, 1);
	}
	if (num == 1)
		ft_putstr_fd(ERR_MLX, 2);
	if (num == 2)
		ft_putstr_fd(EXIT, 1);
	free_game(msl);
	mlx_close_window(msl->mlx);
	mlx_terminate(msl->mlx);
	exit(num);
}

void	free_game(t_map *msl)
{
	free_array(msl->map);
	mlx_delete_image(msl->mlx, msl->img->img_0);
	mlx_delete_image(msl->mlx, msl->img->img_1);
	mlx_delete_image(msl->mlx, msl->img->img_bg);
	mlx_delete_image(msl->mlx, msl->img->img_c);
	mlx_delete_image(msl->mlx, msl->img->img_e);
	mlx_delete_image(msl->mlx, msl->img->img_p);
}
