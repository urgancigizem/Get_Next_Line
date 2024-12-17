/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:26:54 by gurganci          #+#    #+#             */
/*   Updated: 2024/12/10 13:38:22 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*ft_read_file(int fd, char *result)
{
	char	*buffer;
	int		return_byte;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return_byte = 1;
	while (return_byte > 0)
	{
		return_byte = read(fd, buffer, BUFFER_SIZE);
		if (return_byte == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[return_byte] = '\0';
		result = ft_join_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*ft_take_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_update(char *buffer)
{
	int		i;
	int		j;
	int		len_file;
	char	*new_line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	len_file = ft_strlen(buffer);
	new_line = ft_calloc(len_file - i + 1, sizeof(char));
	i++;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	free(buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	result = ft_take_line(buffer[fd]);
	buffer[fd] = ft_update(buffer[fd]);
	return (result);
}
