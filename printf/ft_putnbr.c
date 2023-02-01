/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:24:18 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/26 12:00:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		n *= (-1);
		ft_putchar('-', count);
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}
