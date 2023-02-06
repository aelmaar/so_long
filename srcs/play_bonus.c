/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:53:47 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	close_window(t_inf_b *inf)
{
	destroy_all_bonus(inf, "You destroyed the game");
	return (0);
}

static void	initialize(char **map, t_inf_b *inf)
{
	inf->map = map;
	calc_width_height_bonus(inf->map, inf);
	inf->mlx_ptr = mlx_init();
	inf->win_ptr = mlx_new_window(inf->mlx_ptr, inf->width, \
			inf->height + 60, "so_long");
	inf->path_player = "./textures/player_right.xpm";
	inf->path_exit = "./textures/closed_door.xpm";
	inf->path_collectible = "./textures/collectibles.xpm";
	inf->path_wall = "./textures/wall.xpm";
	inf->path_bg = "./textures/ground.xpm";
	inf->path_enemy = "./textures/hydra1.xpm";
	draw_map_bonus(inf->map, inf);
	component_xy_position(inf->map, &(inf->player_posy), \
		&(inf->player_posx), 'P');
	component_xy_position(inf->map, &(inf->door_posy), &(inf->door_posx), 'E');
	count_collectibles_bonus(inf->map, inf);
	inf->count_moves = 0;
	inf->enemies = NULL;
	enemies_x_y_positions(inf->map, &(inf->enemies));
	inf->temp = inf->enemies;
	inf->enemy_length = ft_lstsize(inf->enemies);
}

void	play_game(char **map)
{
	t_inf_b	inf;

	initialize(map, &inf);
	mlx_hook(inf.win_ptr, 2, 0, key_press_bonus, &inf);
	mlx_hook(inf.win_ptr, 17, 0, close_window, &inf);
	mlx_loop_hook(inf.mlx_ptr, enemy_patrol, &inf);
	mlx_loop(inf.mlx_ptr);
}
