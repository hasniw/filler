/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:15:25 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/11 21:45:39 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

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
	char		**board;
	int			cnt;
	t_point		*p;
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
	int			x;
	int			y;
	int			free;
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
** PARSING
*/

int				ft_init_player(t_args *args, char *line);
int				ft_handle_map(t_args *args);
int				ft_handle_piece(t_args *args);

/*
** FREE
*/

void			free_split(char **tab);
void			free_board(char **str, int n);
int				free_line(char **line, int i);
void			free_all(t_args args);

/*
** RESOLVE
*/

int				ft_resolve(t_args *args);
int				ft_get_min_dist(t_args *args, t_point *tracker);

/*
** CHECK
*/

int				check_p_pos(t_args *args, t_point *tracker);
int				is_good(t_args *args, t_point *p, t_point *t);
int				check_overflow(t_args *args, int x, int y);
int				check_edge(t_args *args, t_point *p);
int				check_good(t_args *args);

/*
** END
*/

int				print_pos(t_args *args);
int				filler_end(t_args *args, int end);

#endif
