/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:41:31 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include"libft.h"
# include "mlx.h"

typedef struct gameVariables
{
	char	**map;

	int		map_y_axis;
	int		map_x_axis;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		moves_count;
	int		strashing;
	int		positionx;
	int		positiony;

	void	*mx;
	void	*win;
	void	*b;
	void	*e;
	void	*strash;
	void	*sub;
	void	*w;
}	t_game;

int			exit_game(t_game *aa);
int			read_map(t_game *aa, char *path);
int			player_input(int key, t_game *aa);
void		place_images(t_game *aa);
void		xpm_to_img(t_game *aa);
void		check_map(t_game *aa);

#endif