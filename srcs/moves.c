/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:33:40 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_info *img)
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

void	move_up(t_info *img)
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

void	move_left(t_info *img)
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

void	move_bottom(t_info *img)
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
	else if (img->map[img->player_posy + 1][img->player_posx] == 'E'
			&& img->collectibles == 0)
		img->player_posy++;
}
