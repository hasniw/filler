/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:23:13 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/06 05:21:01 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static void	ft_get_point_pos(t_args *args)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < args->piece.height)
	{
		j = 0;
		while (args->piece.board[i][j])
		{
			if (args->piece.board[i][j] == '*')
			{
				args->piece.p[cnt].x = j;
				args->piece.p[cnt].y = i;
				args->piece.p[cnt].min = args->point.min;
				cnt++;
			}
			j++;
		}
		i++;
	}
}

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
			return (free_line(&args->line, 1));
		}
		if (args->line[j] == '*')
			args->piece.cnt++;
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
		if ((ret = get_next_line(0, &args->line)) <= 0)
		{
			if (ret == 0)
				free(args->line);
			while (i > 0)
				free(args->map.board[--i]);
			return (1);
		}
		if (ft_check_line(args, i))
			return (1);
		args->piece.board[i++] = ft_strdup(args->line);
		ft_strdel(&args->line);
	}
	args->point.min = args->map.width * args->map.height;
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
		return (free_line(&args->line, 1));
	args->tab = ft_strsplit(args->line, ' ');
	ft_strdel(&args->line);
	if (ft_strcmp("Piece", args->tab[0]))
		return (1);
	args->piece.height = ft_atoi(args->tab[1]);
	args->piece.width = ft_atoi(args->tab[2]);
	free_split(args->tab);
	if (args->piece.height < 1 || args->piece.width < 1)
		return (1);
	return (0);
}

int			ft_handle_piece(t_args *args)
{
	args->piece.cnt = 0;
	if (ft_check_first_line(args))
		return (1);
	if (!(args->piece.board = (char**)malloc(sizeof(char*) *
			args->piece.height)))
		return (1);
	if (ft_piece_assign(args))
		return (1);
	if (!(args->piece.p = (t_point*)malloc(sizeof(t_point) *
			args->piece.cnt)))
		return (1);
	ft_get_point_pos(args);
	return (0);
}
