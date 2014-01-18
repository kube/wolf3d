/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 22:10:36 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/18 22:17:37 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <wolf3d.h>
#include <layer.h>
#include <libft.h>
#include <stdio.h>

static float		calc_dst(t_point a, t_point b)
{
	float			dx;
	float			dy;

	dx = b.x - a.x;
	dy = b.y - a.x;
	return (dx * dx + dy * dy);
}

static int			get_wall_color(t_env *env, t_point impact, int side)
{
	(void)env;
	(void)impact;
	if (side == 1)
	{
		return (0xFF0FFFDD);
	}
	else if (side == 0)
	{
		return (0xFFFFFF00);
	}
	return (0xFFFFFF00);
}

static void			draw_column(t_env *env, t_point impact, int i, int side)
{
	unsigned int	j;
	t_pixel			pixel;
	float			height;
	float			distance;

	j = 0;
	// printf("draw_column %d\n", i);
	// COLOR WILL DEPEND ON HIT SIDE

	distance = calc_dst(env->position, impact);
	pixel.color = get_wall_color(env, impact, side);
	
	height = (env->mlx.win_height / WALL_HEIGHT_SCREEN_PROPORTION) / distance;
	// printf("%X\n", pixel.color);
	while (j < env->mlx.win_height)
	{
		if (j > (env->mlx.win_height - height) / 2 &&
			j < (env->mlx.win_height - height) / 2 + height)
		{
			// printf("a");
			layer_pixel_put(env, env->layers[1], pixel, i, j, 1);
		}
		j++;
	}
	// printf("\n");
}

static t_point		get_vector_to_side(t_point pos, float drv_x, float drv_y)
{
	float			dx;
	float			dy;
	float			dst_side_x;
	float			dst_side_y;
	t_point			to_side;

	if (drv_y < 0)
		dx = - (pos.x - (int)pos.x);
	else
		dx = (int)pos.x + 1 - pos.x;
	if (drv_x < 0)
		dy = - (pos.y - (int)pos.y);
	else
		dy = (int)pos.y + 1 - pos.y;

	// printf("** %f %f\n", dx, dy);
	to_side.x = dx;
	to_side.y = dy;
	if (drv_x == 0.0)
	{
		// printf("a\n");
		to_side.y = 0;
	}
	else if (drv_y == 0.0)
	{
		// printf("b\n");
		to_side.x = 0;
	}
	else
	{
		// printf("c\n");
		dst_side_x = sqrt(dx * dx + dy * drv_x * dy * drv_x);
		dst_side_y = sqrt(dy * dy + dx * drv_y * dx * drv_y);
		if (dst_side_y < dst_side_x)
			to_side.x = dx * drv_y;
		else
			to_side.y = dy * drv_y;
	}
	return (to_side);
}

static void			raycast(t_env *env, t_point pos, float angle, int i)
{
	float			drv_x;
	float			drv_y;
	t_point			to_side;

	
	while (1 && env->map[(int)pos.y][(int)pos.x])
	{
		drv_x = sin(angle);
		drv_y = cos(angle); 
		to_side = get_vector_to_side(pos, drv_x, drv_y);
		pos.x += to_side.x;
		pos.y += to_side.y;

		// printf("%f %f\n", to_side.x, to_side.y);
		// printf("%f %f\n", pos.x, pos.y);

		// break ;

		// Check which side was hit
		if (pos.x - (int)pos.x == 0)
		{
			if (env->map[(int)pos.y][(int)pos.x - (drv_y < 0)]->type == 1)
			{
				// printf("HIT\n\n\n");
				draw_column(env, pos, i, 1);
				break ;
			}
		}
		else
		{
			if (env->map[(int)pos.y - (drv_x < 0)][(int)pos.x]->type == 1)
			{
			// printf("HIT\n\n\n");
				draw_column(env, pos, i, 0);
				break ;
			}
		}

		// HERE IS THE ERROR !!!!!!! CHECK FOR THE ENTIRE FLOAT ONLY !
		// if (env->map[(int)pos.y - (drv_x < 0)][(int)pos.x - (drv_y < 0)]->type == 1)
		// {
			// printf("HIT\n\n\n");
		// }
	}
}

void				trace_view(t_env *env)
{
	unsigned int	i;
	float			angle;
	float			delta_angle;

	i = 0;
	// ft_putstr("a");
	delta_angle = env->params.fov_angle / env->mlx.win_width;
	angle = env->view_angle - (env->params.fov_angle / 2);
	while (i < env->mlx.win_width)
	{
		// printf("NEW\n");
		printf("%f ", angle);
		raycast(env, env->position, angle, i);
		angle += delta_angle;
		i++;
	}
	printf("\n");
	// printf("NEW IMAGE\n");
}
