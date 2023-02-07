/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:39:27 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/04 20:09:30 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_original_map(char **original_map)
{
	char	**map_copy;
	int		map_len;
	int		row;

	map_len = 0;
	while (original_map[map_len] != NULL)
		map_len++;
	map_copy = malloc((map_len + 1) * sizeof(char *));
	row = 0;
	if (map_copy)
	{
		while (original_map[row] != NULL)
		{
			map_copy[row] = ft_strdup(original_map[row]);
			row++;
		}
		map_copy[row] = NULL;
	}
	return (map_copy);
}

static void	check_map_recursively(char **map, int player_posy, int player_posx)
{
	if (map[player_posy][player_posx] == '1')
		return ;
	map[player_posy][player_posx] = '1';
	check_map_recursively(map, player_posy, player_posx + 1);
	check_map_recursively(map, player_posy - 1, player_posx);
	check_map_recursively(map, player_posy, player_posx - 1);
	check_map_recursively(map, player_posy + 1, player_posx);
}

static int	is_valid_map_path(char **map)
{
	int	row;
	int	col;

	col = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'C' || map[col][row] == 'E')
			{
				free_map(map);
				return (0);
			}
			row++;
		}
		col++;
	}
	free_map(map);
	return (1);
}

int	is_valid_path(char **map)
{
	int		player_posx;
	int		player_posy;
	char	**map_copy;

	map_copy = copy_original_map(map);
	player_posx = 0;
	player_posy = 0;
	if (map_copy)
	{
		component_xy_position(map_copy, &player_posy, &player_posx, 'P');
		check_map_recursively(map_copy, player_posy, player_posx);
		if (is_valid_map_path(map_copy))
			return (1);
		else
			return (0);
	}
	return (0);
}
