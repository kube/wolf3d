/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:10:50 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 22:29:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			store_map_points(t_map_square **map_line, char *line)
{
	int				i;
	int				x;
	t_map_square	*square;

	x = 0;
	i = 0;
	while (line[i])
	{
		square = (t_map_square*)ft_memalloc(sizeof(t_map_square));
		while (line[i] && ft_isdigit(line[i]))
		{
			square->type += line[i] - '0';
			i++;
		}
		map_line[x] = square;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		x++;
	}
}

static void			store_map_lines(int file, t_map_square ***map_data,
									int width)
{
	int				y;
	char			*line;

	y = 0;
	while (y < width && get_next_line(file, &line))
	{
		*map_data = (t_map_square**)malloc(width * sizeof(t_map_square*) + 1);
		// PUT LAST AT 0
		store_map_points(*map_data, line);
		y++;
		map_data++;
		free(line);
	}
}

t_map_square		***get_wolf_map(char *file_name)
{
	int				file;
	char			*line;
	t_map_square	***map_data;

	file = open(file_name, O_RDONLY);
	get_next_line(file, &line);
	map_data = (t_map_square***)malloc(atoi(line) * sizeof(t_map_square**) + 1);
	// PUT LAST AT 0
	get_next_line(file, &line);
	store_map_lines(file, map_data, atoi(line));
	close(file);
	return (map_data);
}
