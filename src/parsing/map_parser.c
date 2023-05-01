/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:21:47 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 11:52:51 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	is_valid_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		else
			charset++;
	}
	return (0);
}

int	is_valid_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!is_valid_charset(map->map[y][x], "10PCE\n"))
				return (0);
			else
				x++;
		}
		y++;
	}
	return (1);
}

int	is_expected_shape(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = ft_strlen(game->map->map[0]);
	while (game->map->map[y] != NULL)
	{
		if (ft_strlen(game->map->map[y]) != x)
			return (0);
		y++;
	}
	return (1);
}

static int	is_wallful(char *str)
{
	while (*str != '\n')
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	is_closed_map(t_game *game)
{
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(game->map->map[y]) - 2;
	while (game->map->map[y] != NULL)
	{
		if (y == 0 || y == (game->map->map_width - 1))
		{
			if (!is_wallful(game->map->map[y]))
				return (0);
		}
		else
		{
			if (game->map->map[y][0] != '1' || game->map->map[y][len] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}
