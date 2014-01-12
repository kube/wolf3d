/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:10:50 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/12 02:08:27 by kube             ###   ########.fr       */
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
	map_line[x] = NULL;
}

static void			store_map_lines(t_env *env, int file,
									t_map_square ***map_data)
{
	int				y;
	char			*line;

	y = 0;
	while (y < env->map_height && get_next_line(file, &line))
	{
		*map_data = (t_map_square**)malloc((env->map_width + 1) * sizeof(t_map_square*));
		store_map_points(*map_data, line);
		y++;
		map_data++;
	}
	*map_data = NULL;
}

static int			get_next_int(int file)
{
	char			*line;
	int				next_int;

	get_next_line(file, &line);
	next_int = ft_atoi(line);
	free(line);
	return (next_int);
}

static void			load_textures(t_env *env, int file)
{
	char			*line;

	(void)env;
	while (get_next_line(file, &line))
	{
		printf("Loading texture : %s...\n", line);
		free(line);
	}
}

void				load_map(t_env *env, char *file_name)
{
	int				file;
	t_map_square	***map_data;

	file = open(file_name, O_RDONLY);
	env->map_height = get_next_int(file);
	env->map_width = get_next_int(file);
	map_data = (t_map_square***)malloc((env->map_height + 1) * sizeof(t_map_square**));
	store_map_lines(env, file, map_data);
	env->position.x = (float)get_next_int(file);
	env->position.y = (float)get_next_int(file);
	load_textures(env, file);
	env->map = map_data;
	close(file);
}
