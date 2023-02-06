/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:41:54 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:16:42 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_info *img)
{
	destroy_all(img, "You destroyed the game");
	return (0);
}

static void	initialize(char **map, t_info *img)
{
	img->map = map;
	calc_width_height(img->map, img);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->width, \
			img->height, "so_long");
	img->path_player = "./textures/player_right.xpm";
	img->path_exit = "./textures/closed_door.xpm";
	img->path_collectible = "./textures/collectibles.xpm";
	img->path_wall = "./textures/wall.xpm";
	img->path_bg = "./textures/ground.xpm";
	draw_map(img->map, img);
	component_xy_position(img->map, &(img->player_posy), \
			&(img->player_posx), 'P');
	component_xy_position(img->map, &(img->door_posy), &(img->door_posx), 'E');
	count_collectibles(img->map, img);
	img->count_moves = 0;
}

void	play_game(char **map)
{
	t_info	img;

	initialize(map, &img);
	mlx_hook(img.win_ptr, 2, 0, key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_loop(img.mlx_ptr);
}
