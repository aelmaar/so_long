/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:41:54 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:20:06 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_inf *inf)
{
	destroy_all(inf, "You destroyed the game");
	return (0);
}

static void	initialize(char **map, t_inf *inf)
{
	inf->map = map;
	calc_width_height(inf->map, inf);
	inf->mlx_ptr = mlx_init();
	inf->win_ptr = mlx_new_window(inf->mlx_ptr, inf->width, \
			inf->height, "so_long");
	inf->path_player = "./textures/player_right.xpm";
	inf->path_exit = "./textures/closed_door.xpm";
	inf->path_collectible = "./textures/collectibles.xpm";
	inf->path_wall = "./textures/wall.xpm";
	inf->path_bg = "./textures/ground.xpm";
	draw_map(inf->map, inf);
	component_xy_position(inf->map, &(inf->player_posy), \
			&(inf->player_posx), 'P');
	component_xy_position(inf->map, &(inf->door_posy), &(inf->door_posx), 'E');
	count_collectibles(inf->map, inf);
	inf->count_moves = 0;
}

void	play_game(char **map)
{
	t_inf	inf;

	initialize(map, &inf);
	mlx_hook(inf.win_ptr, 2, 0, key_press, &inf);
	mlx_hook(inf.win_ptr, 17, 0, close_window, &inf);
	mlx_loop(inf.mlx_ptr);
}
