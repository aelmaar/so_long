/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:13:30 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/26 18:52:04 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned int n, char *hex, int *count)
{
	if (n >= 16)
	{
		ft_hex(n / 16, hex, count);
	}
	ft_putchar(hex[n % 16], count);
}

void	ft_puthex(unsigned int n, char c, int *count)
{
	char	*lower_hex;
	char	*upper_hex;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (c == 'x')
		ft_hex(n, lower_hex, count);
	else
		ft_hex(n, upper_hex, count);
}
