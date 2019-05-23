/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:15:25 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/22 00:44:41 by wahasni          ###   ########.fr       */
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
	t_point		*p;
	char		**board;
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
int				ft_isndigit(char *s, int n);

/*
** INIT PLAYER
*/

int				ft_init_player(t_args *args, char *line);

/*
** MAP
*/

int				ft_handle_map(t_args *args);

/*
** PIECE
*/

int				ft_handle_piece(t_args *args);

#endif