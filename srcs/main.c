/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/02 00:37:52 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		filler_end(t_args *args, int end)
{
	if (end == 1)
	{
		print_pos(args);
		// free(&args->piece);
		args->point.x = 0;
		args->point.y = 0;
		args->point.min = args->map.width * args->map.height;
	}
	else
	{
		// free(args);
		printf("0 0\n");
	}
	return (end);
}

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

void		ft_init(t_args *args)
{
	args->line = NULL;
	args->tab = NULL;
	// ft_bzero(args, sizeof(args))s;
	// ft_memalloc(sizeof(args));
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

int 		main(void)
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
			if (args.map.board[0])
			{
				free_board(args.map.board, args.map.height);
			}
			// ft_strdel(args.piece.board);
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
	// printf("END OF MAIN !!!!\n");
	// printf("map height in main : %d\n", args.map.height);
	
	// __attribute__((destructor)) int end (){
	// while(1);
	// };
	return (0);
}