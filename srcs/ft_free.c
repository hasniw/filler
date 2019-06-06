/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 01:34:30 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/07 00:54:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	free_all(t_args args)
{
	free_board(args.map.board, args.map.height);
	free_board(args.piece.board, args.piece.height);
	free(args.piece.p);
}

int		free_line(char **line, int i)
{
	ft_strdel(line);
	return (i);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_board(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(str[i++]);
	free(str);
}
