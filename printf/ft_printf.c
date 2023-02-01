/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:45:19 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/26 18:51:08 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_type(va_list ap, char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(ap, unsigned long), count);
	else if (c == 'd')
		ft_putnbr(va_arg(ap, int), count);
	else if (c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putunbr(va_arg(ap, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), 'x', count);
	else if (c == 'X')
		ft_puthex(va_arg(ap, unsigned int), 'X', count);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		count_printed;
	va_list	ap;

	va_start(ap, format);
	count_printed = 0;
	while (*format)
	{
		if (*format == '%')
			print_type(ap, *(++format), &count_printed);
		else
			ft_putchar(*format, &count_printed);
		format++;
	}
	va_end(ap);
	return (count_printed);
}
