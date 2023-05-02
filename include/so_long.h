/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:42:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/02 20:49:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include "../src/mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53

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
# define ERR_MLX_INIT "[ERROR]	MLX initialization failed.\n"
# define ERR_MLX_WINDOWS "[ERROR]	MLX Windows as crashed.\n"
# define ERR_IMG_INIT "[ERROR]	IMG initialization failed.\n"

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
	char		charset_save;
}				t_player;

typedef struct s_img
{
	int			height;
	int			width;
	void		*walls;
	void		*floor;
	void		*player_f[3];
	void		*player_b[3];
	void		*player_l[3];
	void		*player_r[3];
	void		*exit_open;
	void		*exit_close;
	void		*coin;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*windows;
	int			w_height;
	int			w_width;
	int			temp_input;
	t_map_data	*map_data;
	t_map		*map;
	t_player	*player;
	t_img		*img;
}				t_game;

//	PARSING

int				is_valid_extension(char *arg);
char			**get_map(char **argv, t_game *game);
void			get_map_items(t_game *game);
int				is_valid_map(t_map *map);
int				is_expected_shape(t_game *game);
int				is_closed_map(t_game *game);
int				path_finding(t_game *game, char **map, int x, int y);

//	MLX

void			init_mlx(t_game *game);
void			init_player(t_game *game);
void			init_items(t_game *game);
void			init_imgs(t_game *game);
void			clear_imgs(t_game *game);
void			display_imgs(t_game *game);
void			do_move(int key, t_game *game);
int				check_input_key(int key, t_game *game);

// INIT STRUCT

t_game			*init_game_struct(t_game *game);

// MEMORY HANDLING

void			exit_faillure(t_game *game, char *error_msg);
int				exit_success(t_game *game);
void			free_tab(char **array);
void			free_map_struct(t_map *map);
#endif