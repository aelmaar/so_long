/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:31:38 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/27 11:36:14 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexa_long(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_puthexa_long(n / 16, count);
	}
	ft_putchar("0123456789abcdef"[n % 16], count);
}

void	ft_putptr(unsigned long p, int *count)
{
	ft_putstr("0x", count);
	if (p < 16)
		ft_putchar("0123456789abcdef"[p], count);
	else
		ft_puthexa_long(p, count);
}
