/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:26:12 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/30 19:28:07 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_not_rectangular(char **map)
{
	int	min_len;
	int	row;

	row = 0;
	min_len = ft_strlen(map[row]);
	while (map[row] != NULL)
	{
		if (min_len != ft_strlen(map[row]))
			return (0);
		row++;
	}
	return (1);
}

int	is_start_exit_duplicated(char **map)
{
	int	col;
	int	row;
	int	start_count;
	int	exit_count;

	start_count = 0;
	exit_count = 0;
	col = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'P')
				start_count++;
			else if (map[col][row] == 'E')
				exit_count++;
			row++;
		}
		col++;
	}
	if (start_count > 1 || exit_count > 1)
		return (0);
	return (1);
}

int	is_valid_map_components(char **map)
{
	int	col;
	int	row;
	int	components_count;
	int	position;

	col = 0;
	components_count = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			position = map[col][row];
			if (position == 'E' || position == 'P' || position == 'C')
				components_count++;
			if (position != 'E' && position != 'P' && position != 'C' \
				&& position != '1' && position != '0')
				return (0);
			row++;
		}
		col++;
	}
	if (components_count < 3)
		return (0);
	return (1);
}

int	is_map_surrounded_by_walls(char **map)
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	while (map[col])
		col++;
	while (map[0][row] && map[col - 1][row])
	{
		if (map[0][row] == '0' || map[col - 1][row] == '0')
			return (0);
		row++;
	}
	col = 0;
	while (map[col] && map[col][0] && map[col][row - 1])
	{
		if (map[col][0] == '0' || map[col][row - 1] == '0')
			return (0);
		col++;
	}
	return (1);
}
