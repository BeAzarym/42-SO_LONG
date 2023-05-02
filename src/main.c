/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:42 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 21:50:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	parse_map(t_game *game, char **argv)
{
	char	**map_cpy;

	game->map->map = get_map(argv, game);
	if (!game->map->map)
		exit_faillure(game, ERR_MALLOC_CRASH);
	if (!is_valid_map(game->map))
		exit_faillure(game, ERR_INVALID_CHARSET);
	if (!is_expected_shape(game))
		exit_faillure(game, ERR_INVALID_MAP_SHAPE);
	if (!is_closed_map(game))
		exit_faillure(game, ERR_MAP_WALL);
	get_map_items(game);
	game->map_data->items = game->map_data->coin + 1;
	map_cpy = ft_arraydup(game->map->map, game->map->map_width);
	if (!map_cpy)
		exit_faillure(game, ERR_MALLOC_CRASH);
	if (!path_finding(game, map_cpy, game->player->x, game->player->y))
	{
		free_tab(map_cpy);
		exit_faillure(game, ERR_PATHFINDING);
	}
	free_tab(map_cpy);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_faillure(NULL, ERR_INVALID_ARG);
	game = NULL;
	game = init_game_struct(game);
	if (!game)
		exit_faillure(game, ERR_MALLOC_CRASH);
	parse_map(game, argv);
	init_mlx(game);
	mlx_hook(game->windows, 17, 0, &exit_success, game);
	mlx_hook(game->windows, KEY_PRESS, 0, &check_input_key, game);
	mlx_loop(game->mlx);
	exit_success(game);
}
