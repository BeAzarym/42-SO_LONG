/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:42:25 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/26 10:18:25 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map_check
{
	int	coin;
	int	player;
	int	obj;
	int	exit;
	int	exit_x;
	int	exit_y;
}		t_map_check;

#endif