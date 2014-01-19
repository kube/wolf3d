/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:16:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/19 20:30:42 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>
#include <mlx.h>
#include <layer.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "/opt/X11/include/X11/X.h"


static int				keypress_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		env->pressed_keys.left = 1;
	if (keycode == 65361)
		env->pressed_keys.right = 1;
	if (keycode == 65362)
		env->pressed_keys.up = 1;
	if (keycode == 65364)
		env->pressed_keys.down = 1;
	return (0);
}

static int				keyrelease_hook(int keycode, t_env *env)
{
	if (keycode == 65363)
		env->pressed_keys.left = 0;
	if (keycode == 65361)
		env->pressed_keys.right = 0;
	if (keycode == 65362)
		env->pressed_keys.up = 0;
	if (keycode == 65364)
		env->pressed_keys.down = 0;
	return (0);
}

static void				init_layers(t_env *env)
{
	int					i;
	t_mlx				*m;

	i = 0;
	m = &env->mlx;
	while (i < LAYERS_NUMBER)
	{
		env->layers[i] = create_layer(m->win_width, m->win_height,
										NORMAL_BLEND, 0.5);
		i++;
	}
}

static int				expose_hook(t_env *env)
{
	if (env->pressed_keys.left)
		env->view_angle += 0.03;
	else if (env->pressed_keys.right)
		env->view_angle -= 0.03;
	if (env->pressed_keys.up)
	{
		env->position.x += 0.04 * cos(env->view_angle);
		env->position.y += 0.04 * sin(env->view_angle);
	}
	else if (env->pressed_keys.down)
	{
		env->position.x -= 0.04 * cos(env->view_angle);
		env->position.y -= 0.04 * sin(env->view_angle);
	}
	trace_view(env);
	bzero(env->mlx.data, env->mlx.win_width * env->mlx.win_height * 4);
	apply_layer(&env->mlx, env->layers[1], 1);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}

static t_pressed_keys	init_pressed_keys()
{
	t_pressed_keys		pressed_keys;

	pressed_keys.up = 0;
	pressed_keys.down = 0;
	pressed_keys.left = 0;
	pressed_keys.right = 0;
	return (pressed_keys);
}

int						main(void)
{
	t_env				env;
	t_mlx				*m;

	m = &env.mlx;
	m->win_width = 1024;
	m->win_height = 768;
	load_map(&env, "maps/example.wolfmap");
	m->mlx = mlx_init();
	env.pressed_keys = init_pressed_keys();
	m->win = mlx_new_window(m->mlx, m->win_width, m->win_height, "42");
	m->img = mlx_new_image(m->mlx, m->win_width, m->win_height);
	m->data = (int*)mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line),
		&(m->endian));
	init_layers(&env);
	env.view_angle = 0.0;
	env.params.fov_angle = 1.0;
	mlx_hook(m->win, KeyPress, KeyPressMask, keypress_hook, &env);
	mlx_hook(m->win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
	mlx_loop_hook(env.mlx.mlx, expose_hook, &env);
	mlx_loop(m->mlx);
	return (0);
}
