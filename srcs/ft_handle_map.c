/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:29:09 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/24 20:32:10 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int	ft_check_first_line(t_args *args)
{
	int		ret;
	int		i;

	i = -1;
	if ((ret = get_next_line(0, &args->line)) != 1)
	{
	    if (ret == 0)
	        free(args->line);
	    return (1);
	}
	while (++i < 4)
	{
		if (args->line[i] != ' ')
		{
			ft_strdel(&args->line);
			printf("first_line space error\n");
			return (1);
		}
	}
	while (args->line[i])
	{
		if (!(ft_isdigit(args->line[i++])))
		{
			ft_strdel(&args->line);
			printf("first_line digit error\n");
			return (1);
		}
	}
	return (0);
}

static int	ft_check_line(t_args *args, int i)
{
	int j;

	j = 4;
	if (ft_count_word(args->line, ' ') != 1 || args->line[3] != ' '
        || ft_strlen(args->line) != (size_t)args->map.width + 4
        || ft_isndigit(args->line, 3))
    {
        while (i > 0)
            free(args->map.board[--i]);
        free(args->line);
        return (1);
    }
	while (args->line[j])
	{
		if (args->line[j] != 'O' && args->line[j] != 'X'
			&& args->line[j] != 'o' && args->line[j] != 'x'
			&& args->line[j] != '.')
		{
			while (i > 0)
            	free(args->map.board[--i]);
        	free(args->line);
        	return (1);
		}
		j++;
	}
	return (0);
}

static int	ft_map_assign(t_args *args)
{
	int		i;
	int		ret;

	i = 0;
	while (i < args->map.height)
	{
		if ((ret = get_next_line(0, &args->line)) != 1)
		{
		    if (ret == 0)
		            free(args->line);
		    while (i > 0)
		            free(args->map.board[--i]);
		    return (1);
		}
		if (ft_check_line(args, i))
			return (1);
		args->map.board[i++] = ft_strsub(args->line, 4, (size_t)args->map.width);
        printf("map board[%d] -> {%s}\n", i - 1, args->map.board[i - 1]);
		ft_strdel(&args->line);
	}
	args->map.board[i] = NULL;
	return (0);
}

static int	ft_check_plateau(t_args *args)
{
	int	ret;

	if ((ret = get_next_line(0, &args->line)) != 1)
    {
        if (ret == 0)
            ft_strdel(&args->line);
        return (1);
	}
	if (ft_count_word(args->line, ' ') != 2)
	{
		ft_strdel(&args->line);
		return (1);
	}
	args->tab = ft_strsplit(args->line, ' ');
	ft_strdel(&args->line);
	if (ft_strcmp("Plateau", args->tab[0]))
		return (1);
	args->map.height = ft_atoi(args->tab[1]);
	args->map.width = ft_atoi(args->tab[2]);
	// free_tab();
	if (args->map.height < 1 || args->map.width < 1)
		return (1);
	////
	return (0);
}

int		ft_handle_map(t_args *args)
{
	if (ft_check_plateau(args))
		return (1);
	printf("Check_plateau BON\n");
	if (!(args->map.board = (char**)malloc(sizeof(char*) * args->map.height)))
		return (1);
	printf("MAP_BOARD MALLOCATED\n");
	if (ft_check_first_line(args))
		return (1);
	printf("First_line map is good\n");
	if (ft_map_assign(args))
		return (1);
	printf("MAP_assign BON\n");
	return (0);
}