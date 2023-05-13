/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:58:15 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/26 15:58:37 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	j;
	size_t	k;

	j = 0;
	k = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (k + 1));
	if (!s2)
		return (NULL);
	while (j < k)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	while (s1[a] != '\0')
	{
		str[b] = s1[a];
		a++;
		b++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		str[b] = s2[a];
		a++;
		b++;
	}
	str[b] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (c >= 255)
		(c -= 256);
	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
