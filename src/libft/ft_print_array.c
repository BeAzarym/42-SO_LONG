/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:59:55 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/29 18:38:40 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_array(char **array)
{
	if (!array)
		return ;
	while (*array != NULL)
	{
		ft_printf("->	%s", *array);
		array++;
	}
}