/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:44:06 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	aa;

	if (argc != 2)
	{
		return (0);
	}
	ft_memset(&aa, 0, sizeof(t_game));
	read_map(&aa, argv[1]);
	check_map(&aa);
	aa.mx = mlx_init();
	aa.win = mlx_new_window(aa.mx, aa.map_x_axis * 49, aa.map_y_axis * 49,
			"Aqua Adventure");
	xpm_to_img(&aa);
	place_images(&aa);
	mlx_key_hook(aa.win, player_input, &aa);
	mlx_hook(aa.win, 17, 0, (void *)exit, 0);
	mlx_loop(&aa.mx);
}

int	exit_game(t_game *aa)
{
	int	line;

	mlx_destroy_window(aa->mx, aa->win);
	free(aa->mx);
	line = 0;
	while (line < aa->map_y_axis - 1)
	{
		free(aa->map[line++]);
	}
	free(aa->map);
	exit(0);
}
