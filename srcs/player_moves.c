/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(t_inf *inf)
{
	if (inf->map[inf->player_posy][inf->player_posx + 1] == 'C')
		inf->collectibles--;
	if (inf->map[inf->player_posy][inf->player_posx + 1] == 'C'\
	|| inf->map[inf->player_posy][inf->player_posx + 1] == '0')
	{
		inf->map[inf->player_posy][inf->player_posx + 1] = 'P';
		inf->map[inf->player_posy][inf->player_posx] = '0';
		inf->player_posx++;
		ft_printf("The moves: %d\n", ++(inf->count_moves));
	}
	else if (inf->map[inf->player_posy][inf->player_posx + 1] == 'E'
			&& inf->collectibles == 0)
		inf->player_posx++;
	inf->path_player = "./textures/player_right.xpm";
}

static void	move_up(t_inf *inf)
{
	if (inf->map[inf->player_posy - 1][inf->player_posx] == 'C')
		inf->collectibles--;
	if (inf->map[inf->player_posy - 1][inf->player_posx] == 'C' \
	|| inf->map[inf->player_posy - 1][inf->player_posx] == '0')
	{
		inf->map[inf->player_posy - 1][inf->player_posx] = 'P';
		inf->map[inf->player_posy][inf->player_posx] = '0';
		inf->player_posy--;
		ft_printf("The moves: %d\n", ++(inf->count_moves));
	}
	else if (inf->map[inf->player_posy - 1][inf->player_posx] == 'E'
			&& inf->collectibles == 0)
		inf->player_posy--;
}

static void	move_left(t_inf *inf)
{
	if (inf->map[inf->player_posy][inf->player_posx - 1] == 'C')
		inf->collectibles--;
	if (inf->map[inf->player_posy][inf->player_posx - 1] == 'C' \
	|| inf->map[inf->player_posy][inf->player_posx - 1] == '0')
	{
		inf->map[inf->player_posy][inf->player_posx - 1] = 'P';
		inf->map[inf->player_posy][inf->player_posx] = '0';
		inf->player_posx--;
		ft_printf("The moves: %d\n", ++(inf->count_moves));
	}
	else if (inf->map[inf->player_posy][inf->player_posx - 1] == 'E'
			&& inf->collectibles == 0)
		inf->player_posx--;
	inf->path_player = "./textures/player_left.xpm";
}

static void	move_down(t_inf *inf)
{
	if (inf->map[inf->player_posy + 1][inf->player_posx] == 'C')
		inf->collectibles--;
	if (inf->map[inf->player_posy + 1][inf->player_posx] == 'C' \
	|| inf->map[inf->player_posy + 1][inf->player_posx] == '0')
	{
		inf->map[inf->player_posy + 1][inf->player_posx] = 'P';
		inf->map[inf->player_posy][inf->player_posx] = '0';
		inf->player_posy++;
		ft_printf("The moves: %d\n", ++(inf->count_moves));
	}
	else if ((inf->map[inf->player_posy + 1][inf->player_posx] == 'E' \
			&& inf->collectibles == 0))
		inf->player_posy++;
}

void	move_player(int keycode, t_inf *inf)
{
	if (keycode == 124)
		move_right(inf);
	else if (keycode == 126)
		move_up(inf);
	else if (keycode == 123)
		move_left(inf);
	else if (keycode == 125)
		move_down(inf);
	else if (keycode == 53)
		destroy_all(inf, "You exit the game", 1);
}
