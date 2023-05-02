/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:43:19 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 18:25:44 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_tab(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_map_struct(t_map *map)
{
	if (!map)
		return ;
	free_tab(map->map);
	free(map);
}

void	ft_free(t_game *game, char *error_msg)
{
	if (game)
	{
		free_map_struct(game->map);
		free(game->map_data);
		free(game->player);
		free(game->img);
		free(game);
	}
	ft_putstr_fd("Error\n", 2);
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}
