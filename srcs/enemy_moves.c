/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:58:22 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 15:53:57 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_enemy_right(t_info_b *img, t_enemy *enemy)
{
	if (img->map[enemy->pos_y][enemy->pos_x + 1] == '0')
	{
		img->map[enemy->pos_y][enemy->pos_x + 1] = 'A';
		img->map[enemy->pos_y][enemy->pos_x] = '0';
		enemy->pos_x++;
	}
	else if (img->map[enemy->pos_y][enemy->pos_x + 1] == 'P')
		enemy->pos_x++;
}

static void	move_enemy_up(t_info_b *img, t_enemy *enemy)
{
	if (img->map[enemy->pos_y - 1][enemy->pos_x] == '0')
	{
		img->map[enemy->pos_y - 1][enemy->pos_x] = 'A';
		img->map[enemy->pos_y][enemy->pos_x] = '0';
		enemy->pos_y--;
	}
	else if (img->map[enemy->pos_y - 1][enemy->pos_x] == 'P')
		enemy->pos_y--;
}

static void	move_enemy_left(t_info_b *img, t_enemy *enemy)
{
	if (img->map[enemy->pos_y][enemy->pos_x - 1] == '0')
	{
		img->map[enemy->pos_y][enemy->pos_x - 1] = 'A';
		img->map[enemy->pos_y][enemy->pos_x] = '0';
		enemy->pos_x--;
	}
	else if (img->map[enemy->pos_y][enemy->pos_x - 1] == 'P')
		enemy->pos_x--;
}

static void	move_enemy_down(t_info_b *img, t_enemy *enemy)
{
	if (img->map[enemy->pos_y + 1][enemy->pos_x] == '0')
	{
		img->map[enemy->pos_y + 1][enemy->pos_x] = 'A';
		img->map[enemy->pos_y][enemy->pos_x] = '0';
		enemy->pos_y++;
	}
	else if (img->map[enemy->pos_y + 1][enemy->pos_x] == 'P')
		enemy->pos_y++;
}

void	move_enemy(t_info_b *img)
{
	int	random;

	random = rand() % 20;
	if (random >= 0 && random <= 5)
		move_enemy_right(img, img->temp);
	else if (random >= 6 && random <= 10)
		move_enemy_up(img, img->temp);
	else if (random >= 11 && random <= 15)
		move_enemy_left(img, img->temp);
	else
		move_enemy_down(img, img->temp);
}
