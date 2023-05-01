/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:42:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 17:52:07 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define ERR_INVALID_ARG "[ERROR]	Invalid number of arguments.\n"
# define ERR_PATH "[ERROR]	Map doesn't exist.\n"
# define ERR_BAD_EXTENSION "[ERROR]	Wrong extension file.\n"
# define ERR_TOO_FEW_PLAYER "[ERROR]	Too few player on map.\n"
# define ERR_TOO_MUCH_PLAYER "[ERROR]	Too much player on map.\n"
# define ERR_TOO_FEW_EXIT "[ERROR]	Too few exit in the map.\n"
# define ERR_TOO_MUCH_EXIT "[ERROR]	Too much exit in the map.\n"
# define ERR_TOO_FEW_COLLECTIBLES "[ERROR]	Too few collectibles in the map.\n"
# define ERR_INVALID_CHARSET "[ERROR]	Invalid charset in the map.\n"
# define ERR_EMPTY_MAP "[ERROR]	Map is empty or a line is empty.\n"
# define ERR_MALLOC_CRASH "[ERROR]	Malloc failed!\n"
# define ERR_INVALID_MAP_SHAPE "[ERROR]	Map must be rectangular.\n"
# define ERR_MAP_WALL "[ERROR]	Map must be closed by wall.\n"
# define ERR_PATHFINDING "[ERROR]	Map is not playable.\n"

typedef struct s_map_data
{
	int			coin;
	int			player;
	int			items;
	int			exit;
	int			exit_x;
	int			exit_y;
}				t_map_data;

typedef struct s_map
{
	char		**map;
	int			map_length;
	int			map_width;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			coin;
	int			move;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*windows;
	int			w_height;
	int			w_width;
	t_map_data	*map_data;
	t_map		*map;
	t_player	*player;
}				t_game;

//	PARSING

int				is_valid_extension(char *arg);
char			**get_map(char **argv, t_game *game);
void			get_map_items(t_game *game);
int				is_valid_map(t_map *map);
int				is_expected_shape(t_game *game);
int				is_closed_map(t_game *game);
int				path_finding(t_game *game, char **map, int x, int y);

// INIT STRUCT
t_game			*init_game_struct(t_game *game);

// MEMORY HANDLING
void			ft_free(t_game *game, char *error_msg);
void			free_tab(char **array);
void			free_map_struct(t_map *map);

#endif