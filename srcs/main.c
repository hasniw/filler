/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/28 23:24:21 by wahasni          ###   ########.fr       */
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
**     Plateau 9 30:
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
		printf("555\n");
		if (ft_handle_map(&args))
		{
			printf("1\n");
			// printf("board : {%s}\n", args.map.board[0]);
			int n = 0;
			while (n < args.map.height)
				free(args.map.board[n++]);
			free(args.map.board);
			// free_split(args.map.board);
			printf("2\n");
			// ft_strdel(args.piece.board);
			printf("3\n");
			return (1);
		}
		printf("MAP OKEY\n");
		if (ft_handle_piece(&args))
		{
			free_split(args.map.board);
			free_split(args.piece.board);
			return (1);
		}
		printf("PIECE OKEY\n");
		// printf("PRINT QUELQUES VALEURS POUR TEST PARSING :");
		// printf("line : {%s}\n", args.line);
		// int i = 0;
		// while (i < args.map.height)
		// {
			// printf("Y = %d, Board : {%s}\n", i, args.map.board[i]);
			// i++;
		// }
		// i = 0;
		// while (i < args.piece.height)
		// {
			// printf("Y = %d, Board : {%s}\n", i, args.piece.board[i]);
			// i++;
		// }
		//end = ft_resolve(&args);
		// free_split(args.piece.board);
		int n = 0;
		while (n < args.piece.height)
			free(args.piece.board[n++]);
		free(args.piece.board);
	}
	printf("END OF MAIN !!!!\n");
	printf("map height in main : %d\n", args.map.height);
	return (0);
}