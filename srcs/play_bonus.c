/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:53:47 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:41:09 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	close_window(t_info_b *img)
{
	destroy_all_bonus(img, "You destroyed the game");
	return (0);
}

static void	initialize(char **map, t_info_b *img)
{
	img->map = map;
	calc_width_height_bonus(img->map, img);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->width, \
			img->height + 60, "so_long");
	img->path_player = "./textures/player_right.xpm";
	img->path_exit = "./textures/closed_door.xpm";
	img->path_collectible = "./textures/collectibles.xpm";
	img->path_wall = "./textures/wall.xpm";
	img->path_bg = "./textures/ground.xpm";
	img->path_enemy = "./textures/hydra1.xpm";
	draw_map_bonus(img->map, img);
	component_xy_position(img->map, &(img->player_posy), \
		&(img->player_posx), 'P');
	component_xy_position(img->map, &(img->door_posy), &(img->door_posx), 'E');
	count_collectibles_bonus(img->map, img);
	img->count_moves = 0;
	img->enemies = NULL;
	enemies_x_y_positions(img->map, &(img->enemies));
	img->temp = img->enemies;
	img->enemy_length = ft_lstsize(img->enemies);
}

void	play_game(char **map)
{
	t_info_b	img;

	initialize(map, &img);
	mlx_hook(img.win_ptr, 2, 0, key_press_bonus, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_loop_hook(img.mlx_ptr, enemy_patrol, &img);
	mlx_loop(img.mlx_ptr);
}
