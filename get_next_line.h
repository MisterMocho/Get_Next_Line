/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luida-cu <luida-cu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:48:47 by luida-cu          #+#    #+#             */
/*   Updated: 2025/10/24 18:02:16 by luida-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

// Helper functions
int		ft_strlgnl(const char *str);
char	*ft_strchr_nullc(const char *s, int c);
char	*ft_strjoin_free(char *s1, char const *s2);
void	new_buffer(char *buffer);

#endif
