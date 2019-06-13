/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:48:40 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/13 05:41:03 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int pow)
{
	double	tmp;

	if (pow == 0)
		return (1);
	tmp = ft_pow(nb, pow / 2);
	if ((pow % 2) == 0)
		return (tmp * tmp);
	else
	{
		if (pow > 0)
			return (nb * tmp * tmp);
		else
			return ((tmp * tmp) / nb);
	}
}
