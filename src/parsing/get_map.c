/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:44:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 19:56:36 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	get_map_width(char **argv)
{
	char	*line;
	int		line_count;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
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

char	**get_map(char **argv, t_game *game)
{
	int	fd;

	if (!is_valid_extension(argv[1]))
		exit_faillure(game, ERR_BAD_EXTENSION);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_faillure(game, ERR_PATH);
	game->map->map = malloc(sizeof(char *) * (get_map_width(argv) + 1));
	if (!game->map->map)
		exit_faillure(game, ERR_MALLOC_CRASH);
	while (1)
	{
		game->map->map[game->map->map_width] = get_next_line(fd);
		if (!game->map->map[game->map->map_width])
			break ;
		game->map->map_width++;
	}
	game->map->map[game->map->map_width] = NULL;
	game->map->map_length = ft_strlen(game->map->map[0]);
	close(fd);
	return (game->map->map);
}
