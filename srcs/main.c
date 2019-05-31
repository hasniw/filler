/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/31 04:44:36 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

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
	while (end)
	{
		if (ft_handle_map(&args))
		{
			if (args.map.board[0])
			{
				printf("nanmamaamammaa\n");
				free_board(args.map.board, args.map.height);
				printf("yoyoyoyoyoyo\n");
			}
			printf("2\n");
			// ft_strdel(args.piece.board);
			printf("3\n");
			return (1);
		}
		printf("MAP OKEY\n");
		if (ft_handle_piece(&args))
		{
			if (args.map.board)
				free_board(args.map.board, args.map.height);
			free_board(args.piece.board, args.piece.height);
			return (1);
		}
		printf("PIECE OKEY\n");
		end = ft_resolve(&args);
		printf("end : %d\n", end);
		free_board(args.piece.board, args.piece.height);		
	}
	printf("END OF MAIN !!!!\n");
	printf("map height in main : %d\n", args.map.height);
	return (0);
}