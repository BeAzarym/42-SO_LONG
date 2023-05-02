/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:43:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 22:26:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clear_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->player_f[0]);
	mlx_destroy_image(game->mlx, game->img->player_f[1]);
	mlx_destroy_image(game->mlx, game->img->player_f[2]);
	mlx_destroy_image(game->mlx, game->img->player_f[3]);
	mlx_destroy_image(game->mlx, game->img->player_r[0]);
	mlx_destroy_image(game->mlx, game->img->player_r[1]);
	mlx_destroy_image(game->mlx, game->img->player_r[2]);
	mlx_destroy_image(game->mlx, game->img->player_r[3]);
	mlx_destroy_image(game->mlx, game->img->player_b[0]);
	mlx_destroy_image(game->mlx, game->img->player_b[1]);
	mlx_destroy_image(game->mlx, game->img->player_b[2]);
	mlx_destroy_image(game->mlx, game->img->player_b[3]);
	mlx_destroy_image(game->mlx, game->img->player_l[0]);
	mlx_destroy_image(game->mlx, game->img->player_l[1]);
	mlx_destroy_image(game->mlx, game->img->player_l[2]);
	mlx_destroy_image(game->mlx, game->img->player_l[3]);
}
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
	clear_imgs(game);
}
