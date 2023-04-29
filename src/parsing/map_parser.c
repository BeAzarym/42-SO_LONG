/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:21:47 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/29 20:50:19 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	is_valid_charset(char c, char *charset)
{
	while (charset)
	{
		if (c == *charset)
			return (1);
		else
			charset++;
	}
	return (0);
}

int	get_map_width(char **argv)
{
	char	*line;
	int		line_count;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_count++;
		free(line);
	}
	close(fd);
	return (line_count);
}

int	is_valid_extension(char *arg)
{
	char	*resultat;

	resultat = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (!resultat)
		return (0);
	if (resultat && *(resultat + 4) == '\0')
		return (1);
	return (0);
}

char	**get_map(char **argv, t_game *game)
{
	int	fd;

	if (!is_valid_extension(argv[1]))
		ft_free(game, ERR_BAD_EXTENSION);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_free(game, ERR_PATH);
	game->map->map = malloc(sizeof(char *) * (get_map_width(argv) + 1));
	if (!game->map->map)
		return (NULL);
	while (1)
	{
		game->map->map[game->map->map_width] = get_next_line(fd);
		if (!game->map->map[game->map->map_width])
			break ;
		game->map->map_width++;
	}
	game->map->map[game->map->map_width] = NULL;
	close(fd);
	return (game->map->map);
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
			if (is_valid_charset(map->map[y][x], "10PCE\n"))
				x++;
			else
				return (0);
		}
		y++;
	}
	return (1);
}
