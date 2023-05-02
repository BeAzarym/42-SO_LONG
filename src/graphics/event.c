/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:52:12 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 22:43:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_input_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_success(game);
	mlx_clear_window(game->mlx, game->windows);
	do_move(key, game);
	if (game->player->move > 0 && game->temp_input != game->player->move)
	{
		if (game->player->move >= 2)
			ft_putstr_fd("Steps: ", 1);
		else
			ft_putstr_fd("Step:	", 1);
		ft_putnbr_fd(game->player->move, 1);
		ft_putstr_fd("\n", 1);
		game->temp_input = game->player->move;
	}
	display_imgs(game);
	return (0);
}
