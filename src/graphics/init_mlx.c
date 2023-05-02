/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:56:28 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 23:57:18 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_faillure(game, ERR_MLX_INIT);
	game->w_height = game->map->map_width * 16;
	game->w_width = game->map->map_length * 16;
	game->windows = mlx_new_window(game->mlx, game->w_width, game->w_height
			+ 16, "A Simple game");
	if (!game->windows)
		exit_faillure(game, ERR_MLX_WINDOWS);
	init_items(game);
	display_imgs(game);
}
