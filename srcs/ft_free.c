/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 01:34:30 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/06 02:24:47 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

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
