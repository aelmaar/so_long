/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:18:51 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(t_info *img)
{
	if (img->map[img->player_posy][img->player_posx + 1] == 'C')
		img->collectibles--;
	if (img->map[img->player_posy][img->player_posx + 1] == 'C'\
	|| img->map[img->player_posy][img->player_posx + 1] == '0')
	{
		img->map[img->player_posy][img->player_posx + 1] = 'P';
		img->map[img->player_posy][img->player_posx] = '0';
		img->player_posx++;
		ft_printf("The moves: %d\n", ++(img->count_moves));
	}
	else if (img->map[img->player_posy][img->player_posx + 1] == 'E'
			&& img->collectibles == 0)
		img->player_posx++;
	img->path_player = "./textures/player_right.xpm";
}

static void	move_up(t_info *img)
{
	if (img->map[img->player_posy - 1][img->player_posx] == 'C')
		img->collectibles--;
	if (img->map[img->player_posy - 1][img->player_posx] == 'C' \
	|| img->map[img->player_posy - 1][img->player_posx] == '0')
	{
		img->map[img->player_posy - 1][img->player_posx] = 'P';
		img->map[img->player_posy][img->player_posx] = '0';
		img->player_posy--;
		ft_printf("The moves: %d\n", ++(img->count_moves));
	}
	else if (img->map[img->player_posy - 1][img->player_posx] == 'E'
			&& img->collectibles == 0)
		img->player_posy--;
}

static void	move_left(t_info *img)
{
	if (img->map[img->player_posy][img->player_posx - 1] == 'C')
		img->collectibles--;
	if (img->map[img->player_posy][img->player_posx - 1] == 'C' \
	|| img->map[img->player_posy][img->player_posx - 1] == '0')
	{
		img->map[img->player_posy][img->player_posx - 1] = 'P';
		img->map[img->player_posy][img->player_posx] = '0';
		img->player_posx--;
		ft_printf("The moves: %d\n", ++(img->count_moves));
	}
	else if (img->map[img->player_posy][img->player_posx - 1] == 'E'
			&& img->collectibles == 0)
		img->player_posx--;
	img->path_player = "./textures/player_left.xpm";
}

static void	move_down(t_info *img)
{
	if (img->map[img->player_posy + 1][img->player_posx] == 'C')
		img->collectibles--;
	if (img->map[img->player_posy + 1][img->player_posx] == 'C' \
	|| img->map[img->player_posy + 1][img->player_posx] == '0')
	{
		img->map[img->player_posy + 1][img->player_posx] = 'P';
		img->map[img->player_posy][img->player_posx] = '0';
		img->player_posy++;
		ft_printf("The moves: %d\n", ++(img->count_moves));
	}
	else if ((img->map[img->player_posy + 1][img->player_posx] == 'E' \
			&& img->collectibles == 0))
		img->player_posy++;
}

void	move_player(int keycode, t_info *img)
{
	if (keycode == 124)
		move_right(img);
	else if (keycode == 126)
		move_up(img);
	else if (keycode == 123)
		move_left(img);
	else if (keycode == 125)
		move_down(img);
	else if (keycode == 53)
		destroy_all(img, "You exit the game");
}
