/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:01:47 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/03 16:42:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_enemy	*ft_lstnew(int pos_x, int pos_y)
{
	t_enemy	*new;

	new = ft_calloc(1, sizeof(t_enemy));
	if (new)
	{
		new->pos_x = pos_x;
		new->pos_y = pos_y;
		new->next = 0;
	}
	return (new);
}
