/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luida-cu <luida-cu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:39:02 by luida-cu          #+#    #+#             */
/*   Updated: 2025/10/24 18:02:14 by luida-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlgnl(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\n' && str[i])
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr_nullc(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	ssize_t	i;
	ssize_t	j;
	char	*ns;

	ns = malloc(ft_strlgnl(s1) + ft_strlgnl(s2) + 1);
	if (!ns)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	j = -1;
	while (++j < BUFFER_SIZE && s2[j] && s2[j] != '\n')
		ns[i + j] = s2[j];
	if (s2[j] == '\n')
	{
		ns[i + j] = s2[j];
		j++;
	}
	ns[i + j] = '\0';
	return (free(s1), ns);
}

void	new_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = -1;
	while (buffer[++j + i])
		buffer[j] = buffer[j + i];
	buffer[j] = '\0';
}
