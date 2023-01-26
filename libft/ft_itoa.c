/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:28:16 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/04 13:02:35 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	calc_size_int(int n)
{
	long	nb;
	short	len;

	nb = n;
	len = 0;
	if (n == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= (-1);
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	short	size;

	size = calc_size_int(n);
	res = ft_calloc(size + 1, sizeof(char));
	nb = n;
	if (n == 0)
		res[0] = 48;
	if (res)
	{
		res[size--] = '\0';
		if (nb < 0)
		{
			res[0] = '-';
			nb *= (-1);
		}
		while (nb > 0)
		{
			res[size--] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	return (res);
}
