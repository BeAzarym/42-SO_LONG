/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:21:47 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/27 13:42:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	char *resultat;

	resultat = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (!resultat)
		return (0);
	if (resultat && *(resultat + 4) == '\0')
		return (1);
	return (0);
}
