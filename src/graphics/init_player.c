/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:17:12 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 21:00:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_forward(t_game *game)
{
	game->img->player_f[0] = mlx_xpm_file_to_image(game->mlx, "src/img/F_1.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_f[0])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_f[1] = mlx_xpm_file_to_image(game->mlx, "src/img/F_2.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_f[1])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_f[2] = mlx_xpm_file_to_image(game->mlx, "src/img/F_3.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_f[2])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_f[3] = mlx_xpm_file_to_image(game->mlx, "src/img/F_4.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_f[3])
		exit_faillure(game, ERR_IMG_INIT);
}

static void	init_backward(t_game *game)
{
	game->img->player_b[0] = mlx_xpm_file_to_image(game->mlx, "src/img/B_1.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_b[0])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_b[1] = mlx_xpm_file_to_image(game->mlx, "src/img/B_2.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_b[1])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_b[2] = mlx_xpm_file_to_image(game->mlx, "src/img/B_3.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_b[2])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_b[3] = mlx_xpm_file_to_image(game->mlx, "src/img/B_4.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_b[3])
		exit_faillure(game, ERR_IMG_INIT);
}

static void	init_right(t_game *game)
{
	game->img->player_r[0] = mlx_xpm_file_to_image(game->mlx, "src/img/R_1.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_r[0])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_r[1] = mlx_xpm_file_to_image(game->mlx, "src/img/R_2.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_r[1])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_r[2] = mlx_xpm_file_to_image(game->mlx, "src/img/R_3.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_r[2])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_r[3] = mlx_xpm_file_to_image(game->mlx, "src/img/R_4.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_r[3])
		exit_faillure(game, ERR_IMG_INIT);
}

static void	init_left(t_game *game)
{
	game->img->player_l[0] = mlx_xpm_file_to_image(game->mlx, "src/img/L_1.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_l[0])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_l[1] = mlx_xpm_file_to_image(game->mlx, "src/img/L_2.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_l[1])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_l[2] = mlx_xpm_file_to_image(game->mlx, "src/img/L_3.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_l[2])
		exit_faillure(game, ERR_IMG_INIT);
	game->img->player_l[3] = mlx_xpm_file_to_image(game->mlx, "src/img/L_4.xpm",
			&game->img->width, &game->img->height);
	if (!game->img->player_l[3])
		exit_faillure(game, ERR_IMG_INIT);
}

void	init_player(t_game *game)
{
	init_forward(game);
	init_backward(game);
	init_right(game);
	init_left(game);
}
