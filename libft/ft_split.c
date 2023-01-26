/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:05:37 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/08 15:51:16 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_delimiter(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static size_t	calc_size_strs(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s && check_delimiter(*s, c))
			s++;
		if (*s && !check_delimiter(*s, c))
			len++;
		while (*s && !check_delimiter(*s, c))
			s++;
	}
	return (len);
}

static char	*alloc_word(char *s, char delimiter)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && !check_delimiter(s[len], delimiter))
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (word)
	{
		while (i < len)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	size_strs;
	size_t	i;

	if (!s)
		return (0);
	size_strs = calc_size_strs((char *)s, c);
	strs = (char **)ft_calloc(size_strs + 1, sizeof(char *));
	i = 0;
	if (strs)
	{
		while (*s)
		{
			while (*s && check_delimiter(*s, c))
				s++;
			if (*s && !check_delimiter(*s, c))
			{
				strs[i++] = alloc_word((char *)s, c);
			}
			while (*s && !check_delimiter(*s, c))
				s++;
		}
		strs[i] = 0;
	}
	return (strs);
}
