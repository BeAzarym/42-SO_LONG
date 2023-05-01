/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:42 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 11:48:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void parse_map(t_game *game, char **argv)
{
	game->map->map = get_map(argv, game);
	if (!game->map->map)
		ft_free(game, ERR_MALLOC_CRASH);
	if (!is_valid_map(game->map))
		ft_free(game, ERR_INVALID_CHARSET);
	if (!is_expected_shape(game))
		ft_free(game, ERR_INVALID_MAP_SHAPE);
	if (!is_closed_map(game))
		ft_free(game, ERR_MAP_WALL);
	get_map_items(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_free(NULL, ERR_INVALID_ARG);
	game = NULL;
	game = init_game_struct(game);
	if (!game)
		ft_free(game, ERR_MALLOC_CRASH);
	parse_map(game, argv);
	ft_print_array(game->map->map);
	ft_free(game, NULL);
}
