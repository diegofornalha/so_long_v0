/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:44:03 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	add_line(t_game *aa, char *line)
{
	char	**temp;
	int		i;

	if (!line)
	{
		return (0);
	}
	i = 0;
	aa->map_y_axis++;
	temp = malloc(sizeof(char *) * (aa->map_y_axis + 1));
	temp[aa->map_y_axis] = NULL;
	while (i < aa->map_y_axis - 1)
	{
		temp[i] = aa->map[i];
		i++;
	}
	temp[i] = line;
	if (aa->map)
	{
		free(aa->map);
	}
	aa->map = temp;
	return (1);
}

static int	map_width(char *row)
{
	int	width;

	width = 0;
	while (row[width] != '\0')
	{
		width++;
	}
	if (row[width - 1] == '\n')
	{
		width--;
	}
	return (width);
}

int	read_map(t_game *aa, char *path)
{
	char	*map_contents;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	while (1)
	{
		map_contents = get_next_line(fd);
		if (!add_line(aa, map_contents))
		{
			break ;
		}
	}
	close(fd);
	aa->map_x_axis = map_width(aa->map[0]);
	return (1);
}
