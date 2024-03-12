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
	is_dir(argv[1]);
}

void	is_dir(char *dir)
{
	int fd;
	
	fd = open(dir, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_putstr_fd(ERR_DIR, 2);
		close(fd);
		exit(1);
	}
	close(fd);
	return ;
} 