/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 23:28:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/26 23:33:11 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	pose_piece(t_args *args)
{
	if (ft_check_pos(args))
	{
		if (ft_check_collision(args))
		{
			ft_get_min_dist(args);	
			return (1);
		}
	}
	return (0);
}

int	ft_resolve(t_args *args)
{
	int end;

	while (args->y < args->map.height)
	{
		args->x = 0;
		while(args->x < args->map.width)
		{
			if (args->map.board[args->y][args->x] == args->me)
				end = pose_piece(args);
			args->x++;
		}
		args->y++;
	}
	return (filler_end(args, end));
}