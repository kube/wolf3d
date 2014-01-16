/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:10:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/16 02:02:24 by cfeijoo          ###   ########.fr       */
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

static void			raytracing(t_env *env, t_point pos, float angle, int i)
{
	float			dy;
	float			dx;
	float			dst_side_x;
	float			dst_side_y;
	float			drv_x;
	float			drv_y;

	drv_x = sin(angle);
	drv_y = cos(angle);
	ft_putstr("b");

	while (1 && env->map[(int)pos.y][(int)pos.x])
	{
		ft_putstr("c");
		dx = (int)pos.x - pos.x + (drv_y > 0);
		dy = (int)pos.y - pos.y + (drv_x > 0);

		printf("// %f %f\n", dx, dy);

		dst_side_y = dy * drv_y;
		dst_side_y = sqrt(dy * dy + dx * drv_y * dx * drv_y);
		dst_side_x = dx * drv_x;
		dst_side_y = sqrt(dx * dx + dy * drv_x * dy * drv_x);
		if (dst_side_y < dst_side_x)
		{
			ft_putstr("d1 ");
			pos.x += dx * drv_x;
			pos.y += dy;
		}
		else
		{
			ft_putstr("d2 ");
			pos.x += dx;
			pos.y += dy * drv_y;
		}
		printf("%f %f\n", pos.x, pos.y);
		if (env->map[(int)pos.y][(int)pos.x]->type)
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
