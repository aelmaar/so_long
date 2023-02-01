/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:50:19 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/31 19:39:46 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc == 2)
	{
		map = read_from_map(argv[1]);
		if (map)
		{
			check_map(map);
			play_game(map);
		}
	}
}
