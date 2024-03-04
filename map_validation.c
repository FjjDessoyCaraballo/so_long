/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:18:52 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/01 14:18:53 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* gotta start by checking format of the map, later I can check letters
1. check if is a rectangle (I have width and height in the struct); DONE
2. remove new lines - DONE 
3. check if there are no invalid characters - DONE
4. check if the floor is all 0's - UNNECESSARY!
5. check if the limit walls are all 1's - DONE
6. check if there is at least one C
7. check if there is at least one E
8. check if there is at least one P

OBS: VS code terminal fucks up output, dont trust it always.
*/

void	check_rectangle(t_map msl)
{
	size_t	i;

	i = 0;
	while (i < msl.height)
	{
		if (ft_strlen(msl.map[i]) != msl.width)
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit(1);
		}
		i++;
	}
}

void	check_character(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' &&
			map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putstr_fd(ERR_CHAR, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_map msl) // check if all limit walls are 1
{
	check_upper_wall(msl);
	check_lower_wall(msl);
	check_left_wall(msl);
	check_right_wall(msl);
}

/* diary of progress */
/*
01.03.2024 
1 - My map is coming back in irregular size (not rectangular). 
The last row is coming back with -1 element different 
from the other rows (e.g. 6, 6, 5 for minimap.ber. 
Probably because ft_strlen is not counting the null at the end.)

04.03.2024 
1 - Modded ft_strlen to count until new line. 
Now the struct has the true value of the width 
for any possible scenario. Modded strlen is in utils.c.
2 - In remove_nl() I will insert a new variable in the 
struct that will take the parsed map, while leaving the
original map unnafected. As the name says, this function 
will take out the newlines. 
3 - New map has been inserted to the struct. Now the array 
has just null terminated strings in it. Next step is to 
check if the map is a rectangle.
4 - Added check_character() that rejects maps with invalid
characters in the map.
5 - Added multiple checks for the limit walls. If any given
map is not contained by 1's, the map is rejected with its
own error message.
END OF DAY: next step is to check for at least one occurrence
of P, E, and C. 
*/
