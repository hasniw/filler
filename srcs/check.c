/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/12 04:07:09 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_good(t_args *args)
{
	int i;

	i = 0;
	while (i < args->piece.cnt)
	{
		if (args->piece.p[i].good)
			return (1);
		i++;
	}
	return (0);
}

int	check_edge(t_args *args, t_point *p)
{
	if ((p->y - 1 > 0) && args->map.board[p->y - 1][p->x] == '.')
		return (1);
	if ((p->y + 1 < args->map.height)
		&& args->map.board[p->y + 1][p->x] == '.')
		return (1);
	if ((p->x + 1 < args->map.width)
		&& args->map.board[p->y][p->x + 1] == '.')
		return (1);
	if ((p->x - 1 > 0) && args->map.board[p->y][p->x - 1] == '.')
		return (1);
	return (0);
}

int	check_overflow(t_args *args, int x, int y)
{
	if (y < 0)
		return (0);
	if (x < 0)
		return (0);
	if (y >= args->map.height)
		return (0);
	if (x >= args->map.width)
		return (0);
	return (1);
}

int	is_good(t_args *args, t_point *p, t_point *t)
{
	int i;
	int x1;
	int y1;

	i = 0;
	while (i < args->piece.cnt)
	{
		y1 = (args->piece.p[i].y - p->y + t->y);
		x1 = (args->piece.p[i].x - p->x + t->x);
		if (i == p->i)
			i++;
		else
		{
			if (!check_overflow(args, x1, y1))
				return (0);
			if (args->map.board[y1][x1] != '.')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_p_pos(t_args *args, t_point *tracker)
{
	t_point p;

	p.i = 0;
	while (p.i < args->piece.cnt)
	{
		p.x = args->piece.p[p.i].x;
		p.y = args->piece.p[p.i].y;
		args->piece.p[p.i].good = is_good(args, &p, tracker);
		p.i++;
	}
	return (check_good(args));
}
