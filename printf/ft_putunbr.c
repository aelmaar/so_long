/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:09:18 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/26 12:00:34 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *count)
{
	if (n > 9)
		ft_putunbr(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}