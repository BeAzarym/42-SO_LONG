/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:43:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 23:55:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	clear_imgs(t_game *game)
{
	if (game->img->coin)
		mlx_destroy_image(game->mlx, game->img->coin);
	if (game->img->exit_close)
		mlx_destroy_image(game->mlx, game->img->exit_close);
	if (game->img->exit_open)
		mlx_destroy_image(game->mlx, game->img->exit_open);
	if (game->img->floor)
		mlx_destroy_image(game->mlx, game->img->floor);
	if (game->img->walls)
		mlx_destroy_image(game->mlx, game->img->walls);
	if (game->img->player)
		mlx_destroy_image(game->mlx, game->img->player);
}
