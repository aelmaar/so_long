/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:00:00 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
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

static void	enemy_animation(t_inf_b *inf, int x, int y)
{
	static int	i;
	int			loop_enemy;

	loop_enemy = inf->enemy_length * 2;
	if (i <= loop_enemy)
		inf->path_enemy = "./textures/hydra1.xpm";
	else if (i <= loop_enemy * 2)
		inf->path_enemy = "./textures/hydra2.xpm";
	else if (i <= loop_enemy * 3)
		inf->path_enemy = "./textures/hydra3.xpm";
	else if (i <= loop_enemy * 4)
		inf->path_enemy = "./textures/hydra4.xpm";
	else if (i <= loop_enemy * 5)
		inf->path_enemy = "./textures/hydra5.xpm";
	else
		i = 0;
	i++;
	load_xpm_image_bonus(inf->map[y][x], inf, x * 60, y * 60 + 60);
	load_xpm_image_bonus(inf->map[inf->temp->pos_y][inf->temp->pos_x], \
			inf, inf->temp->pos_x * 60, inf->temp->pos_y * 60 + 60);
}

int	enemy_patrol(t_inf_b *inf)
{
	int			prev_pos_x;
	int			prev_pos_y;

	if (inf->temp)
	{
		prev_pos_x = inf->temp->pos_x;
		prev_pos_y = inf->temp->pos_y;
		move_enemy(inf);
		if (inf->map[inf->temp->pos_y][inf->temp->pos_x] == 'P')
			destroy_all_bonus(inf, "Game over, The enemy touched you");
		enemy_animation(inf, prev_pos_x, prev_pos_y);
		inf->temp = inf->temp->next;
		usleep(5000);
		mlx_do_sync(inf->mlx_ptr);
	}
	if (inf->temp == NULL)
		inf->temp = inf->enemies;
	return (0);
}
