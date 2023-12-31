/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:04:58 by jucalder          #+#    #+#             */
/*   Updated: 2023/07/10 18:10:43 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_fd(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != '\0')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = remainder;
		remainder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

static char	*extract_line(char *line)
{
	size_t	line_length;
	char	*remaining;

	line_length = 0;
	while (line[line_length] != '\n' && line[line_length] != '\0')
		line_length++;
	if (line[line_length] == '\0' || line[1] == '\0')
		return (0);
	remaining = ft_substr(line, line_length + 1, ft_strlen(line) - line_length);
	if (*remaining == '\0')
	{
		free(remaining);
		remaining = NULL;
	}
	line[line_length + 1] = '\0';
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_from_fd(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = extract_line(line);
	return (line);
}
