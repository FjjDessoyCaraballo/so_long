## ACRONYMS

In case you have no idea what those letters mean:
1. msl - map so_long;
2. mlx - MiniLibraryX;
3. isl - images so_long;

## CHECK LIST

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
14. choose sprites - DONE
15. create a function that opens a window - DONE
16. shove sprites inside the window - DONE
17. check for only .ber files - DONE
18. hook key commands - DONE
19. check for collision - DONE
20. player collects collectibles - ONGOING 
21. player access exit after collecting - 
22. clean exit - 
23. error handling - 

OBS: VS code terminal fucks up output, dont trust it always.

## MLX

What is the MLX?
The MiniLibX, or MLX, is a framework built by Olivier Crouzet on top of X11, a window system developed back in 1984! The MLX is a beginner-friendly C API to interact with the X11 system behind it. Let's look at some of the functions you might be using.

1. mlx_init: Initialises the MLX library. Must be called before using any other functions.
2. mlx_new_window: Creates a new window instance.
3. mlx_hook: Registers events.
4. mlx_loop: Loops over the MLX pointer, triggering each hook in order of registration.
5. mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
6. mlx_put_image_to_window: Puts your image to the screen at the given coordinates.
7. mlx_destroy_image: Frees the image.
8. mlx_destroy_window: Frees the window instance.
9. mlx_destroy_display: Frees MLX.
We will be looking into each function in more detail later, 
but if you want more information about these functions, I 
recommend visiting 42Docs, as they have done a great job 
documenting the MLX (linked in additional resources).

## JOURNAL

```
01.03.2024

1. Map is coming back in irregular size (not rectangular). 
The last row is coming back with -1 element different 
from the other rows (e.g. 6, 6, 5 for minimap.ber. 
Probably because ft_strlen is not counting the null 
at the end.)
```
```
04.03.2024

1. Modded ft_strlen to count until new line. Now the 
struct has the true value of the width for any possible 
scenario. Modded strlen is in utils.c.
2. In remove_nl() I will insert a new variable in the 
struct that will take the parsed map, while leaving the
original map unnafected. As the name says, this function 
will take out the newlines. 
3. New map has been inserted to the struct. Now the array 
has just null terminated strings in it. Next step is to 
check if the map is a rectangle.
4. Added check_character() that rejects maps with invalid
characters in the map.
5. Added multiple checks for the limit walls. If any given
map is not contained by 1's, the map is rejected with its
own error message.
END OF DAY: next step is to check for at least one occurrence
of P, E, and C.
```
```
05.03.2024

1. Added check_components to check existence of necessary
elements in the game - i.e. one player and exit, and at least
one collectible.
2. Map_validation now has check_content() that checks for
existence of ONE occurrence of exit and player.
3. Added a collectibles.c with count_collect() to have the
number of collectibles into my msl struct for further use.
The function only allow the map to have at least ONE
collectible. 
```
```
06.03.2024

1. Added variables size_t x and y_ppos (player position) to
precisely know where the player will be. This information
allows us to have a starting point for the flood_fill later.
2. Added flood_fill function and file. The algorithm floods
the map (on empty spaces, aka 0's) with x's until there is
no other space (0) left. It does so by calling recursively
the function adding/subtracting y and x -which are determined
by the x_ppos and y_ppos - until it hits 1's (walls).
3. The flood_fill definitely does its job, however, there
is no way to check for the existence of an exit yet. The 
idea for checking the exit is exactly checking that it
does NOT exist after the flood fill. Because if it is
still there, it means that the flood fill has not covered
the area where the exit is, therefore making it impossible
to reach.
```
```
07.03.2024

1. Added a function check_fill_exit() to check if there is
still an exit after flooding the map.
2. Added function copy_map() to make a backup copy of the map
before proceeding to fill the map. The backup is neccessary
because after the flood fill algorithm the map will be ripped
of the positions of the player, collectibles, and etc.
3. Copy_map() was using ft_memcpy() and it was somehow
copying after the flood_fill, which was after the copy. The
behavior was corrected by using ft_strdup() and now we can
flood the duplicate without affecting the original map.
4. Copy_map() was leaking due to a lack of space for the
null terminator in the first malloc().
```
```
09.03.2024

1. Added is_dir() to arg_input.c to check for when the given 
file is a directory. Together with this, a specific error message 
is given to this specific error.
```
```
11.03.2024

1. MLX42 is working with the Makefile.
2. Inserted mlx functions mlx_init() to open window, and mlx_loop()
to keep window open.
3. Added texture_loading function to so_long.c, which leads to 
draw_map.c where textures will be turned into images unto the
window.
```
```
12.03.2024

1. Texture_loading() has been reassigned to img_init() in the same
file. There is a need to initialize and determine some variables
before loading sprites/images.
2. Added resize_image() and tile_size() to determine tile size and
resize images accordingly.
3. Tile_size() has been moved up to so_long() for mlx_init() to size
the window to the proper background size.
4. BE CAREFUL: mlx_close_window() can unnecessarily free stuff. Use
it as the last possible thing after all the code.
```
```
13.03.2024

1. Sprites need to have a bit of a white edge to look more aesthetic.
Therefore new sprites were procured.
2. New sprites with white edges have been selected. Sprites resizing
has been changed. Now mlx_resize_image() second and third parameter
are both tile_sq so aspect ratio is maintained in different windows.
3. File map_alllocation.c has been created to handle most of the
mlx_image_to_window() many calls for all variables of the map. There
is map_allocation_x() for each of the variables (x = P, E, C, 0 and 1)
4. Also for the sake of saving space, I've added costumary index i & j
to the struct, saving me couple lines here and there to follow norm.
5. In map_allocation_c/p/e it was added also mlx_image_to_window() to
have a zero (0) on the background of each of the characters. This way
if the sprite is hidden for any game purposes, a zero will display
instead of just plain background.
6. Added file controls.c to handle controls of the game. So far the
file has player_controls() and keyf(). The keyf() is a callback function
for the mlx_key_hook(), which takes the keyf() address.
7. The msl struct has been called in keyf() so we can point to mlx 
struct from there.
8. First key hook was added: esc. Right now the game runs and exits
without any problems. To be more specific, the exiting is due to the
pressing of the key ESC.
```
```
14.03.2024

1. Added file controls_logic.c that contins all movement hooks of
the player. The logic right now is fairly simple: movement will not
be impeded until player hits a one (1). Move up decreases y_ppos 
(t_map) by one; move down increases y_ppos by one; move left
decreases x_ppos by one; and move right increases x_ppos by one.
2. By the end of each movement function there is a line pointing
to the img variable, which points to img_p, which points to
instances, which points to x and y (depending on direction). This
line is required to move the image of the player without necessarily
rendering the map over again and again.
3. Variable x_epos and y_epos were added to the t_map struct to
keep the exit position.
4. Added variable p_move (player move) in each movement funciton to
keep track of player movement that should be later be displayed
either in terminal or window.
```

