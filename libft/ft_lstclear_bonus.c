/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:55:54 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:08:41 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_enemy **lst)
{
	t_enemy	*temp_node;

	if (lst)
	{
		while (*lst)
		{
			temp_node = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(temp_node);
		}
		*lst = 0;
	}
}
