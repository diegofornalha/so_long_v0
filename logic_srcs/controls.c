/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:43:52 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_position(t_game *aa, int x, int y)
{
	if (aa->map[y][x] == '0')
	{
		aa->map[y][x] = 'P';
		aa->positionx = x;
		aa->positiony = y;
		aa->moves_count++;
	}
	if (aa->map[y][x] == 'C')
	{
		aa->map[y][x] = 'P';
		aa->positionx = x;
		aa->positiony = y;
		aa->strashing--;
		aa->moves_count++;
	}
	if (aa->map[y][x] == 'E')
	{
		if (aa->strashing != 0)
			return (0);
		else
			ft_printf("\e[35m\e[1m\nCongratulations! All strashing collected!\e[0m \n");
		exit_game(aa);
	}
	return (1);
}

static int	up_or_down(t_game *aa, int key)
{
	int	x;
	int	y;

	x = aa->positionx;
	y = aa->positiony;
	if (key == 13)
	{
		y--;
		if (aa->map[y][x] == '1')
			return (0);
		if (!(check_position(aa, x, y)))
			return (0);
		aa->map[y + 1][x] = '0';
	}
	else if (key == 1)
	{
		y++;
		if (aa->map[y][x] == '1')
			return (0);
		if (!(check_position(aa, x, y)))
			return (0);
		aa->map [y - 1][x] = '0';
	}
	ft_printf("\e[34m\e[1mMoves: %i\n\e[0m", aa->moves_count);
	return (1);
}

static int	left_or_right(t_game *aa, int key)
{
	int	x;
	int	y;

	x = aa->positionx;
	y = aa->positiony;
	if (key == 0)
	{
		x--;
		if (aa->map[y][x] == '1')
			return (0);
		if (!(check_position(aa, x, y)))
			return (0);
		aa->map[y][x + 1] = '0';
	}
	else if (key == 2)
	{
		x++;
		if (aa->map[y][x] == '1')
			return (0);
		if (!(check_position(aa, x, y)))
			return (0);
		aa->map[y][x - 1] = '0';
	}
	ft_printf("\e[34m\e[1mMoves: %i\n\e[0m", aa->moves_count);
	return (1);
}

int	player_input(int key, t_game *aa)
{
	int	event;

	if (key == 13 || key == 1)
	{
		event = up_or_down(aa, key);
	}
	if (key == 0 || key == 2)
	{	
		event = left_or_right(aa, key);
	}
	if (key == 53)
	{
		exit_game(aa);
	}
	if (event)
	{
		place_images(aa);
	}
	return (1);
}
