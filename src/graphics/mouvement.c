/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:35:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 22:17:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	game_event(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y][x] == 'C')
		game->player->coin++;
	else if (game->map->map[y][x] == 'E'
			&& game->map_data->coin == game->player->coin)
		exit_success(game);
}

static void	move_y(char key, t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	if (key == KEY_UP || key == KEY_W)
	{
		y = --game->player->y;
		game->player->move++;
		game_event(game);
		game->map->map[y][x] = 'P';
		game->map->map[y + 1][x] = game->player->charset_save;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		y = ++game->player->y;
		game->player->move++;
		game_event(game);
		game->map->map[y][x] = 'P';
		game->map->map[y - 1][x] = game->player->charset_save;
	}
}

static void	move_x(char key, t_game *game)
{
	int	x;
	int	y;

	y = game->player->y;
	if (key == KEY_RIGHT || key == KEY_D)
	{
		x = ++game->player->x;
		game->player->move++;
		game_event(game);
		game->map->map[y][x] = 'P';
		game->map->map[y][x - 1] = game->player->charset_save;
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		x = --game->player->x;
		game->player->move++;
		game_event(game);
		game->map->map[y][x] = 'P';
		game->map->map[y][x + 1] = game->player->charset_save;
	}
}

void	do_move(int key, t_game *game)
{
	int	x;
	int	y;
	int	exit_x;
	int	exit_y;

	x = game->player->x;
	y = game->player->y;
	exit_x = game->map_data->exit_x;
	exit_y = game->map_data->exit_y;
	game->player->charset_save = '0';
	if (game->map->map[y][x] == game->map->map[exit_y][exit_x])
		game->player->charset_save = 'E';
	if (game->map->map[y - 1][x] != '1' && (key == KEY_W || key == KEY_UP))
		move_y((char)key, game);
	else if (game->map->map[y + 1][x] != '1' && (key == KEY_S
				|| key == KEY_DOWN))
		move_y((char)key, game);
	else if (game->map->map[y][x - 1] != '1' && (key == KEY_A
				|| key == KEY_LEFT))
		move_x((char)key, game);
	else if (game->map->map[y][x + 1] != '1' && (key == KEY_D
				|| key == KEY_RIGHT))
		move_x((char)key, game);
}
