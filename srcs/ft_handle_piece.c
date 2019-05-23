/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:23:13 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/22 00:56:36 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int	ft_check_line(t_args *args, int i)
{
	int j;

	j = 0;
	while (args->line[j])
	{
		if ((args->line[j] != '.' && args->line[j] != '*')
			|| (ft_strlen(args->line) != (size_t)args->piece.width))
		{
			while (i > 0)
				free(args->piece.board[--i]);
			free(args->line);
			return (1);
		}
		j++;
	}
	return (0);
}

static int	ft_piece_assign(t_args *args)
{
	int	i;
	int ret;

	i = 0;
	while (i < args->piece.height)
	{
		if ((ret = get_next_line(0, &args->line)) != 1)
		{
			if (ret == 0)
				free(args->line);
			while (i > 0)
				free(args->map.board[--i]);
			return (1);
		}
		if (ft_check_line(args, i))
			return (1);
		args->piece.board[i++] = ft_strsub(args->line,
			4, (size_t)args->map.width);
		//i++;
		ft_strdel(&args->line);
	}
	args->piece.board[i] = NULL;
	return (0);
}

static int	ft_check_first_line(t_args *args)
{
	int		ret;

	if ((ret = get_next_line(0, &args->line)) != 1)
	{
		if (ret == 0)
			free(args->line);
		return (1);
	}
	if (ft_count_word(args->line, ' ') != 2)
	{
		ft_strdel(&args->line);
		return (1);
	}
	args->tab = ft_strsplit(args->line, ' ');
	ft_strdel(&args->line);
	if (ft_strcmp("Piece", args->tab[0]))
		return (1);
	args->piece.height = ft_atoi(args->tab[1]);
	args->piece.width = ft_atoi(args->tab[2]);
	// free_tab();
	if (args->piece.height < 1 || args->piece.width < 1)
		return (1);
	return (0);
}

int			ft_handle_piece(t_args *args)
{
	if (ft_check_first_line(args))
		return (1);
	if (!(args->piece.board = (char**)malloc
		(sizeof(char*) * args->piece.height)))
		return (1);
	if (ft_piece_assign(args))
		return (1);
	return (0);
}
