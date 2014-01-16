/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:16:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/16 01:26:04 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>
#include <mlx.h>
#include <layer.h>
#include <stdio.h>

static void			init_layers(t_env *env)
{
	int				i;
	t_mlx			*m;

	i = 0;
	m = &env->mlx;
	while (i < LAYERS_NUMBER)
	{
		env->layers[i] = create_layer(m->win_width,	m->win_height,
										NORMAL_BLEND);
		i++;
	}
}

static int				expose_hook(t_env *env)
{
	ft_putstr("Trace");
	trace_view(env);
	apply_layer(&env->mlx, env->layers[1]);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}

int					main(int argc, char **argv)
{
	t_env			env;
	t_mlx			*m;

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
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->win_width, m->win_height, "42");
	m->img = mlx_new_image(m->mlx, m->win_width, m->win_height);
	m->data = (int*)mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line),
		&(m->endian));
	init_layers(&env);

	env.view_angle = 0;
	env.params.fov_angle = 3.14;
	
	mlx_loop_hook(env.mlx.mlx, expose_hook, &env);
	mlx_loop(m->mlx);
	return (0);
}
