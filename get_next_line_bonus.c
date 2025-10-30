/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luida-cu <luida-cu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:48:31 by luida-cu          #+#    #+#             */
/*   Updated: 2025/10/24 18:02:12 by luida-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || BUFFER_SIZE > 10000000)
		return (NULL);
	line = NULL;
	line = ft_strjoin_free(line, buffer[fd]);
	while (!ft_strchr_nullc(buffer[fd], '\n'))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0 || buffer[fd][0] == '\0')
			return (free(line), new_buffer(buffer[fd]), NULL);
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[fd][bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer[fd]);
	}
	new_buffer(buffer[fd]);
	return (line);
}
