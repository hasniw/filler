/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 01:31:39 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/02 21:41:04 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_init(t_args *args)
{
	args->line = NULL;
	args->tab = NULL;
}

int		ft_init_map(t_args *args)
{
	int	i;

	if (!(args->map.board = (char**)malloc(sizeof(char*)
		* args->map.height)))
		return (1);
	i = 0;
	while (i < args->map.height)
	{
		if (!(args->map.board[i] = (char*)malloc(sizeof(char)
		* args->map.width + 1)))
			return (1);
		ft_bzero(args->map.board[i], args->map.width);
		i++;
	}
	return (0);
}
