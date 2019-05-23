/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isndigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 04:38:14 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/22 01:04:25 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int ft_isndigit(char *s, int n)
{
    int  i;

    i = 0;
    while (s[i] || i < n)
    {
        if (!ft_isdigit(s[i]))
            break;
        i++;
    }
    return (i == (int)ft_strlen(s));
}