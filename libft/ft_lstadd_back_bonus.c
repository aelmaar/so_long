/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:36:51 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/03 16:39:53 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*temp_lst;

	temp_lst = (*lst);
	if (temp_lst)
	{
		while ((temp_lst)->next != 0)
			temp_lst = temp_lst->next;
		temp_lst->next = new;
		return ;
	}
	*lst = new;
}
