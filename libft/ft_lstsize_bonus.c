/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:59:12 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/03 16:41:02 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_enemy *lst)
{
	int	lst_len;

	lst_len = 0;
	while (lst != 0)
	{
		lst_len++;
		lst = lst->next;
	}
	return (lst_len);
}
