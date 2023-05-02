/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:26:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 20:58:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_items(t_game *game)
{
	game->img->coin = mlx_xpm_file_to_image(game->mlx, "src/img/coins.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->coin)
		exit_faillure(game, ERR_IMG_INIT);
	game->img->floor = mlx_xpm_file_to_image(game->mlx, "src/img/floor.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->floor)
		exit_faillure(game, ERR_IMG_INIT);
	game->img->walls = mlx_xpm_file_to_image(game->mlx, "src/img/WALL.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->walls)
		exit_faillure(game, ERR_IMG_INIT);
	game->img->exit_close = mlx_xpm_file_to_image(game->mlx, "src/img/DOOR_1.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->exit_close)
		exit_faillure(game, ERR_IMG_INIT);
	game->img->exit_open = mlx_xpm_file_to_image(game->mlx, "src/img/DOOR_2.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->exit_close)
		exit_faillure(game, ERR_IMG_INIT);
}
