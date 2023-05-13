/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:57:03 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/26 15:57:25 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	*print_line(char *hand)
{
	char	*line;
	int		a;

	a = 0;
	if (!hand)
		return (NULL);
	line = (char *)malloc(sizeof(char) * ft_strlen(hand) + 1);
	if (!line)
		return (NULL);
	while (hand[a])
	{
		line[a] = hand[a];
		a++;
		if (line[a - 1] == '\n')
			break ;
	}
	line[a] = '\0';
	return (line);
}

char	*next_line(char *hand)
{
	char	*next_line;
	int		a;
	int		b;

	a = 0;
	while (hand[a] && hand[a] != '\n')
		a++;
	if (!hand[a] || !hand[a + 1])
		return (free(hand), NULL);
	if (hand)
		a++;
	next_line = (char *)malloc(sizeof(char) * ft_strlen(hand + a) + 1);
	if (!next_line)
		return (free(hand), NULL);
	b = 0;
	while (hand[a])
	{
		next_line[b] = hand[a];
		b++;
		a++;
	}
	next_line[b] = '\0';
	free(hand);
	return (next_line);
}

char	*read_bytes(int fd, int bytes, char *hand, char *buffer)
{
	char	*temp;

	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (!hand)
			hand = ft_strdup("");
		temp = hand;
		hand = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (hand);
}

char	*get_next_line(int fd)
{
	static char	*hand[OPEN_MAX];
	char		*buffer;
	char		*lines;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (free(buffer), NULL);
	hand[fd] = read_bytes(fd, bytes, hand[fd], buffer);
	if (!hand[fd])
		return (free(buffer), free(hand[fd]), NULL);
	free(buffer);
	lines = print_line(hand[fd]);
	hand[fd] = next_line(hand[fd]);
	return (lines);
}
