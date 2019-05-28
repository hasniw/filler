/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:59:43 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/28 23:15:20 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int  ft_assign_player(t_args *args)
{
	if (args->tab[2] && ft_strcmp(args->tab[2], "p1") == 0)
    {
        args->me = 'O';
        args->ennemy = 'X';
		return (0);
    }
    else if (args->tab[2] && ft_strcmp(args->tab[2], "p2") == 0)
    {
        args->me = 'X';
        args->ennemy = 'O';
		return (0);
    }
	return (1);
}

static int  ft_check_line(t_args *args)
{
	if (ft_strcmp("$$$", args->tab[0]))
        return (1);
    if (ft_strcmp("exec", args->tab[1]))
        return (1);
    if (ft_strcmp(":", args->tab[3]))
        return (1);
    if (ft_strcmp("[./wahasni.filler]", args->tab[4]))
        return (1);
    return (0);
}

void    free_split(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab); 
}

int         ft_init_player(t_args *args, char *line)
{
	int     ret;

	if ((ret = get_next_line(0, &line)) != 1)
    {
        if (ret == 0)
            free(line);
        printf("111\n");
        return (1);
	}
    printf("222\n");
    if (ft_count_word(line, ' ') != 4)
    {
        ft_strdel(&line);
        return (1);
    }
	args->tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (ft_check_line(args))
    {
        ft_strdel(args->tab);
        return (1);
    }
	if (ft_assign_player(args))
		return (1);
    free_split(args->tab);
	return (0);
}