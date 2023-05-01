/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:59:58 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/01 10:00:30 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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