/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:17:15 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/29 19:03:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static t_map_data	*init_map_data_struct(t_map_data *map)
{
	map = malloc(sizeof(t_map_data));
	if (!map)
		return (NULL);
	map->coin = 0;
	map->player = 0;
	map->items = 0;
	map->exit = 0;
	map->exit_x = -1;
	map->exit_y = -1;
	return (map);
}

static t_map	*init_map_struct(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->map_cpy = NULL;
	map->map_length = 0;
	map->map_width = 0;
	return (map);
}

t_game	*init_game_struct(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->windows = NULL;
	game->w_height = 0;
	game->w_width = 0;
	game->map_data = NULL;
	game->map_data = init_map_data_struct(game->map_data);
	if (!game->map_data)
		return (NULL);
	game->map = NULL;
	game->map = init_map_struct(game->map);
	if (!game->map)
		return (NULL);
	return (game);
}
