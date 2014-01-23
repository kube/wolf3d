/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:10:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/23 21:35:08 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>
#include <layer.h>
#include <libft.h>
#include <stdio.h>

static int			get_wall_color(t_env *env, int side)
{
	(void)env;
	if (side == 1)
		return (0xFF0FFFDD);
	else if (side == 0)
		return (0xFFFFFF00);
	return (0xFFFFFF00);
}

static void			draw_column(t_env *env, float distance, int i, int side)
{
	unsigned int	j;
	t_pixel			pixel;
	int				height;

	j = 0;
	pixel.color = get_wall_color(env, side);
	height = (int)((float)env->mlx.win_height / (distance + 1));
	while (j < env->mlx.win_height)
	{
		if (j > (env->mlx.win_height - height) / 2 &&
			j < (env->mlx.win_height - height) / 2 + height)
			layer_pixel_put(env, env->layers[1], pixel, i, j, 1);
		j++;
	}
}

// static void			raycast(t_env *env, t_point pos, float angle, int i)
// {
// 	float			drv_x;
// 	float			drv_y;
// 	t_point			to_side;
// 	float			distance;

// 	distance = 0;
// 	while (1 && env->map[(int)pos.y][(int)pos.x])
// 	{
// 		drv_x = sin(angle);
// 		drv_y = cos(angle);
// 		to_side = get_vector_to_side(pos, drv_x, drv_y);
// 		distance += sqrt(to_side.x * to_side.x + to_side.y * to_side.y);
// 		pos.x += to_side.x;
// 		pos.y += to_side.y;
// 		if (pos.x - (int)pos.x == 0)
// 		{
// 			if (env->map[(int)pos.y][(int)pos.x - (drv_y < 0)]->type == 1)
// 			{
// 				draw_column(env, distance, i, 1);
// 				break ;
// 			}
// 		}
// 		else
// 		{
// 			if (env->map[(int)pos.y - (drv_x < 0)][(int)pos.x]->type == 1)
// 			{
// 				draw_column(env, distance, i, 0);
// 				break ;
// 			}
// 		}
// 	}
// }

static t_point		get_vector_to_side(t_point pos, float drv_x, float drv_y)
{
	float			dx;
	float			dy;
	float			dst_side_x;
	float			dst_side_y;
	t_point			to_side;

	if (drv_x < 0)
	{
		dx = -(pos.x - (int)pos.x);
		// dx -= (dx == 0.0);
	}
	else
		dx = (int)pos.x + 1 - pos.x;
	if (drv_y < 0)
	{
		dy = - (pos.y - (int)pos.y);
		// dy -= (dy == 0.0);
	}
	else
		dy = (int)pos.y + 1 - pos.y;
	to_side.x = dx;
	to_side.y = dy;
	dst_side_x = sqrt(dx * dx + dx * drv_x * dx * drv_x);
	dst_side_y = sqrt(dy * dy + dy * drv_y * dy * drv_y);
	if (dst_side_y < dst_side_x)
		to_side.y = dx * drv_x;
	else
		to_side.x = dy * drv_y;
	return (to_side);
}

static void			raycast(t_env *env, t_point pos, float angle, int i)
{
	float			cosa;
	float			sina;
	float			distance;
	t_point			to_side;

	distance = 0;
	cosa = cos(angle);
	sina = sin(angle);
	while (1 && env->map[(int)pos.y][(int)pos.x])
	{
		pos.x += cosa;
		pos.y += sina;
		distance += 1;
		if (env->map[(int)pos.y][(int)pos.x]->type == 1)
		{
			to_side = get_vector_to_side(pos, -cosa, -sina);
			pos.x -= to_side.x;
			pos.y -= to_side.y;
			distance -= sqrt(to_side.x * to_side.x + to_side.y * to_side.y);
			draw_column(env, distance, i, 0);
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
	delta_angle = env->params.fov_angle / env->mlx.win_width;
	angle = env->view_angle - (env->params.fov_angle / 2);
	while (i < env->mlx.win_width)
	{
		raycast(env, env->position, angle, i);
		angle += delta_angle;
		i++;
	}
}
