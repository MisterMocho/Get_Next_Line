/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luida-cu <luida-cu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:48:31 by luida-cu          #+#    #+#             */
/*   Updated: 2025/10/24 18:02:16 by luida-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_strjoin_free(line, buffer);
	while (!ft_strchr_nullc(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == '\0')
			return (free(line), new_buffer(buffer), NULL);
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer);
	}
	new_buffer(buffer);
	return (line);
}
