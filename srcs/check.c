/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/30 06:37:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

double  calc_min(t_args *args, t_point *t, t_point *p, t_point *ad)
{
	int	i;
	double	min;
	double	res;	
	
	i = 0;
	min = args->point.min;
	while (i < args->piece.cnt)
	{
	        if (i == p->i)
	                i++;
	        else
	        {
	                res = pow((ad->x - (args->piece.p[i].x - p->x + t->x)), 2);
	                res += pow((ad->y - (args->piece.p[i].y - p->y + t->y)), 2);
	                res = sqrt(res);
	                min = res < min ? res : min;
	                i++;
	        }
	}
	return (min);
}

double  calc_min_dist(t_args *args, t_point *tracker, t_point *ad)
{
	t_point	p;
	double	min;
	double	res;

	p.i = 0;
	min = args->point.min;
	ft_bzero(&p, sizeof(p));
	while (p.i < args->piece.cnt)
	{
	    p.x = args->piece.p[p.i].x;
	    p.y = args->piece.p[p.i].y;
	    if (is_good(args, &p, tracker))
	    {
	        res = calc_min(args, tracker, &p, ad);
	        if (res < args->piece.p[p.i].min)
	                args->piece.p[p.i].min = res;
	        min = res < min ? res : min;
	    }
	    p.i++;
	}
	return (min);
}

int		get_min_dist(t_args *args, t_point *tracker)
{
    double  min;
	t_point	ad;

	min = args->map.width * args->map.height;;
	ad.y = 0;
	while (ad.y < args->map.height)
	{
	        ad.x = 0;
	        while (ad.x < args->map.width)
	        {
	                if (args->map.board[ad.y][ad.x] == args->ad)
	                {
	                        min = calc_min_dist(args, tracker, &ad);
	                        if (min < args->point.min)
	                        {
	                                args->point.x = tracker->x;
	                                args->point.y = tracker->y;
	                                args->point.min = min;
	                        }
	                }
	                ad.x++;
	        }
	        ad.y++;
	}
	return (1);
}

int             its_me(t_args *args, t_point *tracker)
{
    if (check_edge(args, tracker))
    {
            if (check_p_pos(args, tracker))
            {
                    get_min_dist(args, tracker);
                    return (1);
            }
    }
    return (0);
}

int	ft_resolve(t_args *args)
{
    t_point	tracker;
	int		end;

	end = 0;
	tracker.y = 0;
	while (tracker.y < args->map.height)
	{
	        tracker.x = 0;
	        while (tracker.x < args->map.width)
	        {
	                if (args->map.board[tracker.y][tracker.x] == args->me)
	                        end = its_me(args, &tracker) ? 1 : end;
	                tracker.x++;
	        }
	        tracker.y++;
	}
	return (args_end(args, end));
}