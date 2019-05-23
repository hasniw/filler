/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:14:48 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/23 04:44:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_init(t_args *args)
{
	args->line = NULL;
	args->tab = NULL;
}

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
		//end = ft_resolve(&args);
	}
	return (0);
}