/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/06 03:35:46 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static void	ft_init(t_args *args)
{
	args->line = NULL;
	args->tab = NULL;
}

int			filler_end(t_args *args, int end)
{
	if (end == 1)
	{
		print_pos(args);
		args->point.x = 0;
		args->point.y = 0;
		args->point.min = args->map.width * args->map.height;
	}
	else
		ft_putstr("0 0\n");
	return (end);
}

int			print_pos(t_args *args)
{
	int		i;
	int		cnt;
	int		x;
	int		y;

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
	ft_putstr(ft_itoa(y));
	ft_putchar(' ');
	ft_putstr(ft_itoa(x));
	ft_putchar('\n');
	return (1);
}

/*
** LINE TEST :
**     $$$ exec p2 : [./wahasni.filler]
**
**     Plateau 2 30:
**         012345678901234567890123456789
**     000 ..............................
**     001 ..............................
**     002 ..X...........................
**     003 ..............................
**     004 ..............................
**     005 ..............................
**     006 ......X.......................
**     007 .......................O......
**     008 ..............................
**
**     Piece 4 7
**     ...*...
**     ...*...
**     ...*...
**     ..***..
*/

int			main(void)
{
	t_args	args;
	int		end;

	end = 1;
	ft_init(&args);
	if (ft_init_player(&args, args.line))
		return (1);
	while (end == 1)
	{
		if (ft_handle_map(&args))
		{
			free_board(args.map.board, args.map.height);
			return (1);
		}
		if (ft_handle_piece(&args))
		{
			if (args.map.board)
				free_board(args.map.board, args.map.height);
			free_board(args.piece.board, args.piece.height);
			return (1);
		}
		end = ft_resolve(&args);
		free_board(args.piece.board, args.piece.height);
	}
	return (0);
}
