/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:42:49 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/28 11:42:50 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(ERR_ARG, 2);
		exit(1);
	}
	if (!ft_strnstr(argv[1], ".ber", 50))
	{
		ft_putstr_fd(ERR_FILE, 2);
		exit(1);
	}
}