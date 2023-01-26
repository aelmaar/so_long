/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:17:51 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 14:27:57 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s > len)
		sub_str = malloc((len + 1) * sizeof(char));
	else
		sub_str = malloc((len_s + 1) * sizeof(char));
	if (!sub_str)
		return (0);
	i = 0;
	if (len_s >= start)
	{
		while (s[start] && i < len)
		{
			sub_str[i] = s[start];
			i++;
			start++;
		}
	}
	sub_str[i] = '\0';
	return (sub_str);
}
