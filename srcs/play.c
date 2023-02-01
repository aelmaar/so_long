/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:41:54 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:46:52 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_press(int keycode, t_info *img)
{
	if (keycode == 124)
		move_right(img);
	else if (keycode == 126)
		move_up(img);
	else if (keycode == 123)
		move_left(img);
	else if (keycode == 125)
		move_bottom(img);
	else if (keycode == 53)
		destroy_all(img, "You exit the game");
	if (img->collectibles == 0)
		img->path_exit = "./textures/open_door.xpm";
	if (img->collectibles == 0 \
		&& img->map[img->player_posy][img->player_posx] == 'E')
		destroy_all(img, "\t\t\t\t\tYOU WIN !!\t\t\t\t\t");
	draw_on_window(img->map, img);
	return (0);
}

static int	close_window(t_info *img)
{
	destroy_all(img, "You destroyed the game");
	return (0);
}

void	play_game(char **map)
{
	t_info	img;

	img.map = map;
	calc_width_height(img.map, &img);
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, img.width, img.height, "so_long");
	img.path_player = "./textures/player_right.xpm";
	img.path_exit = "./textures/closed_door.xpm";
	img.path_collectible = "./textures/collectibles.xpm";
	img.path_wall = "./textures/wall.xpm";
	img.path_bg = "./textures/ground.xpm";
	draw_on_window(img.map, &img);
	player_xy_position(img.map, &(img.player_posy), &(img.player_posx));
	count_collectibles(img.map, &img);
	img.count_moves = 0;
	mlx_hook(img.win_ptr, 2, 0, key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_loop(img.mlx_ptr);
}
