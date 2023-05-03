/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:07:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/03 12:34:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	load_coin_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->windows, game->img->floor, (y
			* 16), (x * 16));
	mlx_put_image_to_window(game->mlx, game->windows, game->img->coin, (y * 16),
		(x * 16));
}

static void	load_player_img(t_game *game, int x, int y)
{
	if (y == game->map_data->exit_x && x == game->map_data->exit_y
		&& game->player->coin < game->map_data->coin)
	{
		mlx_put_image_to_window(game->mlx, game->windows,
			game->img->exit_close, (y * 16), (x * 16));
		mlx_put_image_to_window(game->mlx, game->windows,
			game->img->player, (y * 16), (x * 16));
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->windows, game->img->floor, (y
				* 16), (x * 16));
		mlx_put_image_to_window(game->mlx, game->windows, game->img->player, (y
				* 16), (x * 16));
	}
}

static void	load_img_win(t_game *game, int x, int y, char type)
{
	if (type == '1')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->walls, (y
				* 16), (x * 16));
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->floor, (y
				* 16), (x * 16));
	if (type == 'P')
		load_player_img(game, x, y);
	if (type == 'E')
	{
		if (game->player->coin == game->map_data->coin)
			mlx_put_image_to_window(game->mlx, game->windows,
				game->img->exit_open, (y * 16), (x * 16));
		else
			mlx_put_image_to_window(game->mlx, game->windows,
				game->img->exit_close, (y * 16), (x * 16));
	}
	if (type == 'C')
		load_coin_img(game, x, y);
}

void	display_imgs(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			load_img_win(game, y, x, game->map->map[y][x]);
			x++;
		}
		y++;
	}
}
