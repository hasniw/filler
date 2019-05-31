/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:16:22 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/31 01:10:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int	print_pos(t_args *args)
{
	int i;
	int cnt;
	int x;
	int y;

	i = 0;
	while (i < args->piece.cnt)
	{
		args->piece.p[i].i = i;
		if (is_good(args, &args->piece.p[i], &args->point))
		{
			if (args->piece.p[i].min <= args->point.min)
				cnt = i;
		}
		i++;
	}
	x = args->point.x - args->piece.p[cnt].x;
	y = args->point.y - args->piece.p[cnt].y;
	printf("%d %d\n", y, x);
	return (1);
}
