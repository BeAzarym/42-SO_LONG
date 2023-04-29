/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:42 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/29 20:58:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_free(NULL, ERR_INVALID_ARG);
	game = NULL;
	game = init_game_struct(game);
	if (!game)
		ft_free(game, ERR_MALLOC_CRASH);
	game->map->map = get_map(argv, game);
	if (!game->map->map)
		ft_free(game, ERR_MALLOC_CRASH);
	ft_print_array(game->map->map);
	ft_free(game, NULL);
}
