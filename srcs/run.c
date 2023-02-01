/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:50:19 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 19:30:20 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		{
			ft_putstr_fd("Check the extension if its .ber", 2);
			return (1);
		}
		map = read_from_map(argv[1]);
		if (map)
		{
			check_map(map);
			play_game(map);
		}
	}
	return (0);
}
