/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/24 20:33:28 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_init(t_args *args)
{
	args->line = NULL;
	args->tab = NULL;
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
**     006 ..............................
**     007 ..............................
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
	printf("1\n");
	ft_init(&args);
	// printf("value of init_player : %d\n", ft_init_player(&args, args.line));
	if (ft_init_player(&args, args.line))
	{
		printf("test\n");
		return (1);
	}
	printf("yess\n");
	while (end)
	{
		if (ft_handle_map(&args))
			return (1);
		printf("MAP OKEY\n");
		if (ft_handle_piece(&args))
			return (1);
		printf("PIECE OKEY\n");
		printf("PRINT QUELQUES VALEURS POUR TEST PARSING :");
		printf("line : {%s}\n", args.line);
		int i = 0;
		while (i < args.map.height)
		{
			printf("Y = %d, Board : {%s}\n", i, args.map.board[i]);
			i++;
		}
		i = 0;
		while (i < args.piece.height)
		{
			printf("Y = %d, Board : {%s}\n", i, args.piece.board[i]);
			i++;
		}
		//end = ft_resolve(&args);
	}
	return (0);
}