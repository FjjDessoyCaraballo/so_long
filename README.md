# so_long

1. check if is a rectangle (I have width and height in the struct); DONE
2. remove new lines - DONE 
3. check if there are no invalid characters - DONE
4. check if the floor is all 0's - UNNECESSARY!
5. check if the limit walls are all 1's - DONE
6. check if there is at least one C - DONE
7. check if there is at least one E - DONE
8. check if there is at least one P - DONE
9. account for all collectibles (C) - DONE
10. create a flood fill - DONE
11. create a post-flood fill check for exit - DONE
12. create copy of map - DONE
13. free the copy - DONE
14. choose sprites 
15. create a function that opens a window
16. shove sprites inside the window
17. check for only .ber files - DONE
18. check for directories named .ber - DONE

01.03.2024 
1 - Map is coming back in irregular size (not rectangular). 
The last row is coming back with -1 element different 
from the other rows (e.g. 6, 6, 5 for minimap.ber. 
Probably because ft_strlen is not counting the null 
at the end.)

04.03.2024 
1 - Modded ft_strlen to count until new line. Now the 
struct has the true value of the width for any possible 
scenario. Modded strlen is in utils.c.
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

05.03.2024
1 - Added check_components to check existence of necessary
elements in the game - i.e. one player and exit, and at least
one collectible.
2 - map_validation now has check_content() that checks for
existence of ONE occurrence of exit and player.
3 - Added a collectibles.c with count_collect() to have the
number of collectibles into my msl struct for further use.
The function only allow the map to have at least ONE
collectible. 

06.03.2024
1 - Added variables size_t x and y_ppos (player position) to
precisely know where the player will be. This information
allows us to have a starting point for the flood_fill later.
2 - Added flood_fill function and file. The algorithm floods
the map (on empty spaces, aka 0's) with x's until there is
no other space (0) left. It does so by calling recursively
the function adding/subtracting y and x -which are determined
by the x_ppos and y_ppos - until it hits 1's (walls).
3 - The flood_fill definitely does its job, however, there
is no way to check for the existence of an exit yet. The 
idea for checking the exit is exactly checking that it
does NOT exist after the flood fill. Because if it is
still there, it means that the flood fill has not covered
the area where the exit is, therefore making it impossible
to reach.

07.03.2024
1 - Added a function check_fill_exit() to check if there is
still an exit after flooding the map.\n
2 - Added function copy_map() to make a backup copy of the map
before proceeding to fill the map. The backup is neccessary
because after the flood fill algorithm the map will be ripped
of the positions of the player, collectibles, and etc.
3 - copy_map() was using ft_memcpy() and it was somehow
copying after the flood_fill, which was after the copy. The
behavior was corrected by using ft_strdup() and now we can
flood the duplicate without affecting the original map.
4 - copy_map() was leaking due to a lack of space for the
null terminator in the first malloc().

09.03.2024
Added is_dir() to arg_input.c to check for when the 
given file is a directory. Together with this, a specific
error message is given to this specific error.
