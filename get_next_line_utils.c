/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:42:03 by gurganci          #+#    #+#             */
/*   Updated: 2024/12/03 19:59:33 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	res = malloc(total_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total_len;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_len + 1);
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if ((*s == ch))
			return ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	if (n > 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (res);
}
