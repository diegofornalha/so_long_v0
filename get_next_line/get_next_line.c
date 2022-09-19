/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:39:13 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_new_line(char *line)
{
	char	*remainder;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

static char	*find_new_line(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	line = find_new_line(fd, buffer, backup);
	free(buffer);
	if (!line)
		return (line);
	backup = extract_new_line(line);
	return (line);
}
