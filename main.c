/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:06:01 by jucalder          #+#    #+#             */
/*   Updated: 2023/07/10 19:33:58 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		line_count;

	fd = open ("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open the file.\n");
		return (1);
	}
	line_count = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line %d: %s\n", line_count, line);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	printf("Reached end of file.\n");
	close(fd);
	return (0);
}
