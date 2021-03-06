/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:46:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/13 05:57:53 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**int	ft_sqrt(int nb)
**{
**	int i;
**
**	i = 1;
**	while (i <= nb / i)
**	{
**		if (i * i == nb)
**			return (i);
**		i++;
**	}
**	return (0);
**}
*/

double	ft_sqrt(double nb)
{
	double x;
	double y;
	double e;

	x = nb;
	y = 1;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}
