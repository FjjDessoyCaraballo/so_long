/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:44:50 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/04 13:44:52 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	msl;
	mlx_t	mlx;
	t_img	isl;

	ft_memset(&msl, 0, sizeof(msl));
	invalid_arg(argc, argv);
	msl.img = &isl;
	so_long(&msl, argv, &mlx, &isl);
	return (0);
}
