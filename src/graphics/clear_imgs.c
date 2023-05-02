/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:43:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 19:12:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clear_player_l_r_imgs(t_game *game)
{
	if (game->img->player_l)
	{
		mlx_destroy_image(game->mlx, game->img->player_f[0]);
		mlx_destroy_image(game->mlx, game->img->player_f[1]);
		mlx_destroy_image(game->mlx, game->img->player_f[2]);
		mlx_destroy_image(game->mlx, game->img->player_f[3]);
	}
	if (game->img->player_r)
	{
		mlx_destroy_image(game->mlx, game->img->player_r[0]);
		mlx_destroy_image(game->mlx, game->img->player_r[1]);
		mlx_destroy_image(game->mlx, game->img->player_r[2]);
		mlx_destroy_image(game->mlx, game->img->player_r[3]);
	}
}

static void	clear_player_f_b_imgs(t_game *game)
{
	if (game->img->player_b)
	{
		mlx_destroy_image(game->mlx, game->img->player_b[0]);
		mlx_destroy_image(game->mlx, game->img->player_b[1]);
		mlx_destroy_image(game->mlx, game->img->player_b[2]);
		mlx_destroy_image(game->mlx, game->img->player_b[3]);
	}
	if (game->img->player_f)
	{
		mlx_destroy_image(game->mlx, game->img->player_f[0]);
		mlx_destroy_image(game->mlx, game->img->player_f[1]);
		mlx_destroy_image(game->mlx, game->img->player_f[2]);
		mlx_destroy_image(game->mlx, game->img->player_f[3]);
	}
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
	if (game->img->player_b || game->img->player_f)
		clear_player_f_b_imgs(game);
	if (game->img->player_l || game->img->player_r)
		clear_player_l_r_imgs(game);
}
