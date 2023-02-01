/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:22:03 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 19:48:59 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(char *map_file)
{
	int		size;
	int		fd;
	char	*line_read;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Check if the file exist", 2);
		exit(1);
	}
	line_read = get_next_line(fd);
	size = 0;
	while (line_read != NULL)
	{
		free(line_read);
		line_read = get_next_line(fd);
		size++;
	}
	close(fd);
	return (size);
}

char	**read_from_map(char *map_file)
{
	char	**map;
	char	*line_read;
	int		fd;
	int		row;

	map = malloc((map_size(map_file) + 1) * sizeof(char *));
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit(1);
	if (map)
	{
		row = 0;
		line_read = get_next_line(fd);
		while (line_read != NULL)
		{
			map[row++] = line_read;
			line_read = get_next_line(fd);
		}
		map[row] = NULL;
	}
	close(fd);
	return (map);
}
