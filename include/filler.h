/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:15:25 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/18 18:45:09 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_point
{
	int			i;
	int			x;
	int			y;
	double		min;
	int			good;
}				t_point;

typedef struct	s_piece
{
	int			width;
	int			height;
	int			cnt;
	t_point		*p;
	char		**square;
}				t_piece;

typedef struct	s_map
{
	int			width;
	int			height;
	char		**board;
}				t_map;

typedef struct	s_args
{
	char		me;
	char		ennemy;
	char		*line;
	char		**tab;
	t_map		map;
	t_piece		piece;
	t_point		point;
}				t_args;

/*
** UTILS
*/

int				ft_count_word(char *str, char c);

/*
** INIT PLAYER
*/

int				ft_init_player(t_args *args, char *line);

/*
** MAP
*/

#endif