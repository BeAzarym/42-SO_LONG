/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:12:49 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 18:03:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	init_pos_item(t_game *game, int x, int y, char type)
{
	if (type == 'E')
	{
		game->map_data->exit_x = x;
		game->map_data->exit_y = y;
	}
	else if (type == 'P')
	{
		game->player->x = x;
		game->player->y = y;
	}
}

static void	as_requiered_items(t_game *game)
{
	if (!game->map_data->player)
		ft_free(game, ERR_TOO_FEW_PLAYER);
	else if (game->map_data->player > 1)
		ft_free(game, ERR_TOO_MUCH_PLAYER);
	if (!game->map_data->exit)
		ft_free(game, ERR_TOO_FEW_EXIT);
	else if (game->map_data->exit > 1)
		ft_free(game, ERR_TOO_MUCH_EXIT);
	if (!game->map_data->coin)
		ft_free(game, ERR_TOO_FEW_COLLECTIBLES);
}

void	get_map_items(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->map[++y] != NULL)
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'P')
			{
				game->map_data->player++;
				init_pos_item(game, x, y, 'P');
			}
			else if (game->map->map[y][x] == 'E')
			{
				game->map_data->exit++;
				init_pos_item(game, x, y, 'E');
			}
			else if (game->map->map[y][x] == 'C')
				game->map_data->coin++;
		}
	}
	as_requiered_items(game);
}
