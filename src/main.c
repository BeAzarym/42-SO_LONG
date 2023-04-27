/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:42 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/27 15:23:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**array;
	int		i;

	if (argc != 2)
		return (1);
	if (is_valid_extension(argv[1]))
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	if (fd < 0)
		return (3);
	i = 0;
	array = malloc(sizeof(char *) * (get_map_width(argv) + 1));
	if (!array)
		return (4);
	while (1)
	{
		array[i] = get_next_line(fd);
		if (!array[i])
			break ;
		i++;
	}
	array[i] = NULL;
	close(fd);
	i = 0;
	while (array[i])
	{
		ft_printf("%s", array[i]);
		i++;
	}
}
