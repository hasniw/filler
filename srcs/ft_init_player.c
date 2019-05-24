/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:59:43 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/24 00:09:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int  ft_assign_player(t_args *args)
{
	if (args->tab[2] && ft_strcmp(args->tab[2], "p1") == 0)
    {
        // printf("FIRST ASSIGN PLAYER\n");
        args->me = 'O';
        args->ennemy = 'X';
		return (0);
    }
    else if (args->tab[2] && ft_strcmp(args->tab[2], "p2") == 0)
    {
        // printf("SECOND ASSIGN PLAYER");
        args->me = 'X';
        args->ennemy = 'O';
		return (0);
    }
    printf("error assign\n");
	return (1);
}

static int  ft_check_line(t_args *args)
{
	if (ft_strcmp("$$$", args->tab[0]))
    {
        printf("$$$\n");
        return (1);
    }
    if (ft_strcmp("exec", args->tab[1]))
    {
        printf("exec\n");
        return (1);
    }
    if (ft_strcmp(":", args->tab[3]))
    {
        printf(":\n");
        return (1);
    }
    if (ft_strcmp("[./wahasni.filler]", args->tab[4]))
    {
        printf("./filler : %s\n", args->tab[4]);
        return (1);
    }
    // printf("C'est bueno le check_line\n");
    return (0);
}

int         ft_init_player(t_args *args, char *line)
{
	int     ret;

	if ((ret = get_next_line(0, &line)) != 1)
    {
        printf("GNL false\n");
        if (ret == 0)
            free(line);
        return (1);
	}
    // line = malloc(500);
    // line = "$$$ exec p1 : [./wahasni.filler]\n";
    // printf("%d\n", ft_count_word(line, ' '));
    if (ft_count_word(line, ' ') != 4)
    {
        // ft_strdel(&line);
        printf("count_word false\n");
        return (1);
    }
	args->tab = ft_strsplit(line, ' ');
	// ft_strdel(&line);
    // printf("tab[0] : %s\n", args->tab[0]);
    // printf("tab[1] : %s\n", args->tab[1]);
    // printf("tab[2] : %s\n", args->tab[2]);
    // printf("tab[3] : %s\n", args->tab[3]);
    // printf("tab[4] : %s\n", args->tab[4]);
    // printf("ft_strcmp($$$, args->tab[0] =value=> %d\n", ft_strcmp("$$$", args->tab[0]));
	if (ft_check_line(args))
	{
        printf("check_line false\n");
        return (1);
    }
	if (ft_assign_player(args))
	{
		//free_parse
        printf("assign_false\n");
		return (1);
	}
    // ft_strdel(&line);
	return (0);
}