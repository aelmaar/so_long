/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:00:00 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:37:46 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemies_x_y_positions(char **map, t_enemy **enemy)
{
	int	col;
	int	row;

	col = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'A')
				ft_lstadd_back(enemy, ft_lstnew(row, col));
			row++;
		}
		col++;
	}
}

static void	enemy_animation(t_info_b *img, int x, int y)
{
	static int	i;
	int			loop_enemy;

	loop_enemy = img->enemy_length * 2;
	if (i <= loop_enemy)
		img->path_enemy = "./textures/hydra1.xpm";
	else if (i <= loop_enemy * 2)
		img->path_enemy = "./textures/hydra2.xpm";
	else if (i <= loop_enemy * 3)
		img->path_enemy = "./textures/hydra3.xpm";
	else if (i <= loop_enemy * 4)
		img->path_enemy = "./textures/hydra4.xpm";
	else if (i <= loop_enemy * 5)
		img->path_enemy = "./textures/hydra5.xpm";
	else
		i = 0;
	i++;
	load_xpm_image_bonus(img->map[y][x], img, x * 60, y * 60 + 60);
	load_xpm_image_bonus(img->map[img->temp->pos_y][img->temp->pos_x], \
			img, img->temp->pos_x * 60, img->temp->pos_y * 60 + 60);
}

int	enemy_patrol(t_info_b *img)
{
	int			prev_pos_x;
	int			prev_pos_y;

	if (img->temp)
	{
		prev_pos_x = img->temp->pos_x;
		prev_pos_y = img->temp->pos_y;
		move_enemy(img);
		if (img->map[img->temp->pos_y][img->temp->pos_x] == 'P')
			destroy_all_bonus(img, "Game over, The enemy touched you");
		enemy_animation(img, prev_pos_x, prev_pos_y);
		img->temp = img->temp->next;
		usleep(5000);
		mlx_do_sync(img->mlx_ptr);
	}
	if (img->temp == NULL)
		img->temp = img->enemies;
	return (0);
}
