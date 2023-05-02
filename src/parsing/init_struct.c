/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:17:15 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 09:35:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_map_data	*init_map_data_struct(t_game *game)
{
	game->map_data = malloc(sizeof(t_map_data));
	if (!game->map_data)
		ft_free(game, ERR_MALLOC_CRASH);
	game->map_data->coin = 0;
	game->map_data->player = 0;
	game->map_data->items = 0;
	game->map_data->exit = 0;
	game->map_data->exit_x = -1;
	game->map_data->exit_y = -1;
	return (game->map_data);
}

static t_map	*init_map_struct(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_free(game, ERR_MALLOC_CRASH);
	game->map->map = NULL;
	game->map->map_length = 0;
	game->map->map_width = 0;
	return (game->map);
}

static t_player	*init_player_data(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_free(game, ERR_MALLOC_CRASH);
	game->player->x = -1;
	game->player->y = -1;
	game->player->coin = 0;
	game->player->move = 0;
	return (game->player);
}

static t_img	*init_img_struct(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		ft_free(game, ERR_MALLOC_CRASH);
	game->img->height = -1;
	game->img->width = -1;
	game->img->walls = NULL;
	game->img->floor = NULL;
	game->img->player = NULL;
	game->img->exit_open = NULL;
	game->img->exit_close = NULL;
	game->img->coin = NULL;
	return (game->img);
}

t_game	*init_game_struct(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		ft_free(game, ERR_MALLOC_CRASH);
	game->mlx = NULL;
	game->windows = NULL;
	game->w_height = 0;
	game->w_width = 0;
	game->map_data = NULL;
	game->map_data = init_map_data_struct(game);
	if (!game->map_data)
		ft_free(game, ERR_MALLOC_CRASH);
	game->map = NULL;
	game->map = init_map_struct(game);
	if (!game->map)
		ft_free(game, ERR_MALLOC_CRASH);
	game->player = NULL;
	game->player = init_player_data(game);
	if (!game->player)
		ft_free(game, ERR_MALLOC_CRASH);
	game->img = NULL;
	game->img = init_img_struct(game);
	if (!game->img)
		ft_free(game, ERR_MALLOC_CRASH);
	return (game);
}
