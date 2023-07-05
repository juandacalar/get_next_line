#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>

static char	*join_and_split(char **remainder, char *buffer)
{
	char	*line;
	char	*temp;
	char	*newline_pos;

	temp = ft_strjoin(*remainder, buffer);
	free(*remainder);
	*remainder = temp;
	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*remainder);
		temp = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = temp;
		return (line);
	}
	return (NULL);
}

static char	*read_from_fd(int fd, char **remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = join_and_split(remainder, buffer);
		if (line)
			return (line);
	}
	if (bytes_read == -1 || (bytes_read == 0 && !*remainder))
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = read_from_fd(fd, &remainder);
	if (line)
		return (line);

	if (remainder)
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}

	return (NULL);
}