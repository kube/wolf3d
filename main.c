/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:16:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/14 22:28:07 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			display_map(t_map_square ***map)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%d ", map[j][i]->type);
			i++;
		}
		printf("\n");
		j++;
	}
}

int					main(int argc, char **argv)
{
	t_env			env;
	t_mlx			*m;

	(void)argc;
	(void)argv;
	(void)display_map;
	m = &env.mlx;
	if (argc == 3)
	{
		m->win_width = ft_atoi(argv[1]);
		m->win_height = ft_atoi(argv[2]);
	}
	else
	{
		m->win_width = 1024;
		m->win_height = 768;
	}
	load_map(&env, "maps/example.wolfmap");
	display_map(env.map);
	
	m->mlx = mlx_init();
	
	m->win = mlx_new_window(m->mlx, m->win_width, m->win_height, "42");
	m->img = mlx_new_image(m->mlx, m->win_width, m->win_height);

	m->data = (int*)mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line), &(m->endian));

	
	
	mlx_loop(m->mlx);
	return (0);
}
