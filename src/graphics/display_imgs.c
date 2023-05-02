/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:07:10 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 19:17:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	load_img_win(t_game *game, int x, int y, char type)
{
	if (type == '1')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->walls, (y
				* 16), ((x * 16) + 20));
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->floor, (y
				* 16), ((x * 16) + 20));
	if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->windows,
			game->img->player_f[1], (y * 16), ((x * 16) + 20));
	if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->exit_close,
			(y * 16), ((x * 16) + 20));
	if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->windows, game->img->coin, (y
				* 16), ((x * 16) + 20));
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
