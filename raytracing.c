/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:10:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/17 23:36:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>
#include <layer.h>
#include <libft.h>
#include <stdio.h>

static void			draw_column(t_env *env, float distance, int i)
{
	unsigned int	j;
	t_pixel			pixel;
	float			height;

	j = 0;
	pixel.color = 0xFFFF0000;
	height = WALL_HEIGHT_SCREEN_PROPORTION / distance;
	while (j < env->mlx.win_height)
	{
		if (j > (env->mlx.win_height - height) / 2 &&
			j < (env->mlx.win_height - height) / 2 + height)
			layer_pixel_put(env, env->layers[1], pixel, i, j, 1);
		j++;
	}
}

static float		calc_dst(t_point a, t_point b)
{
	float			dx;
	float			dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	return (sqrt(dx * dx + dy * dy));
}

static t_point		get_vector_to_side(t_point pos, float drv_x, float drv_y)
{
	float			dx;
	float			dy;
	float			dst_side_x;
	float			dst_side_y;
	t_point			to_side;

	if (drv_y < 0)
		dx = (int)pos.x - pos.x;
	else
		dx = (int)pos.x - pos.x;
	if (drv_x < 0)
		dy = (int)pos.y - pos.y;
	else
		dy = (int)pos.y - pos.y;

	printf("** %f %f\n", dx, dy);
	to_side.x = dx;
	to_side.y = dy;
	if (drv_x == 0.0)
	{
		printf("a\n");
		to_side.y = 0;
	}
	else if (drv_y == 0.0)
	{
		printf("b\n");
		to_side.x = 0;
	}
	else
	{
		printf("c\n");
		dst_side_x = sqrt(dx * dx + dy * drv_x * dy * drv_x);
		dst_side_y = sqrt(dy * dy + dx * drv_y * dx * drv_y);
		if (dst_side_y < dst_side_x)
			to_side.x = dx * drv_y;
		else
			to_side.y = dy * drv_y;
	}
	return (to_side);
}

static void			raytracing(t_env *env, t_point pos, float angle, int i)
{
	t_point			to_side;

	
	while (1 && env->map[(int)pos.y][(int)pos.x])
	{
		to_side = get_vector_to_side(pos, sin(angle), cos(angle));
		pos.x += to_side.x;
		pos.y += to_side.y;

		printf("%f %f\n", to_side.x, to_side.y);
		printf("%f %f\n", pos.x, pos.y);

		// break ;

		if (env->map[(int)pos.y][(int)pos.x]->type == 1)
		{
			draw_column(env, calc_dst(env->position, pos), i);
			break ;
		}
	}
}

void				trace_view(t_env *env)
{
	unsigned int	i;
	float			angle;
	float			delta_angle;

	i = 0;
	ft_putstr("a");
	delta_angle = env->params.fov_angle / env->mlx.win_width;
	angle = env->view_angle - env->params.fov_angle / 2;
	while (i < env->mlx.win_width)
	{
		raytracing(env, env->position, angle, i);
		angle += delta_angle;
		i++;
	}
}
