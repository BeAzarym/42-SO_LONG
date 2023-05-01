/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:02:21 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 18:00:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	path_finding(t_game *game, char **map, int x, int y)
{
	char	up;
	char	down;
	char	left;
	char	right;

	if (game->map_data->items == 0)
		return (1);
	up = map[y - 1][x];
	down = map[y + 1][x];
	left = map[y][x - 1];
	right = map[y][x + 1];
	if (map[y][x] == 'C' || map[y][x] == 'E')
		game->map_data->items--;
	map[y][x] = 'x';
	if (up != '1' && up != 'x')
		path_finding(game, map, x, y - 1);
	if (down != '1' && down != 'x')
		path_finding(game, map, x, y + 1);
	if (left != '1' && left != 'x')
		path_finding(game, map, x - 1, y);
	if (right != '1' && right != 'x')
		path_finding(game, map, x + 1, y);
	if (game->map_data->items == 0)
		return (1);
	return (0);
}
