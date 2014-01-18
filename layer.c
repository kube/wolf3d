/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:43:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/18 22:01:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <layer.h>
#include <stdlib.h>
#include <wolf3d.h>
#include <color.h>

// TESTS
#include <strings.h>
#include <stdio.h>

/*
**	We'll add other Blend Modes here later
*/

t_layer				*create_layer(unsigned int width, unsigned int height,
									int blend_mode, float opacity)
{
	t_layer			*layer;

	layer = (t_layer*)malloc(sizeof(t_layer));
	layer->display = 1;
	layer->width = width;
	layer->height = height;
	layer->blend_mode = blend_mode;
	layer->opacity = opacity;
	layer->data = (t_pixel*)malloc(width * height * sizeof(int));
	return (layer);
}

void				apply_layer(t_mlx *mlx, t_layer *layer, int clear)
{
	unsigned int	i;
	t_pixel			*dst;
	t_pixel			*src;

	i = 0;
	src = (t_pixel*)layer->data;
	dst = (t_pixel*)mlx->data;
	while (i < mlx->win_height * mlx->win_width)
	{
		dst[i] = blend_pixels(dst + i, src + i, layer->opacity);
		i++;
	}
	(void)clear;
	if (clear == 1)
		bzero(layer->data, mlx->win_width * mlx->win_height * 4);
}

void				layer_pixel_put(t_env *env, t_layer *layer, t_pixel pixel,
									unsigned int x, unsigned int y, float opacity)
{
	unsigned int	i;

	i = env->mlx.win_width * y + x;
	if (i < env->mlx.win_width * env->mlx.win_height
		&& x < env->mlx.win_width)
		layer->data[i] = blend_pixels((t_pixel*)&layer->data[i], &pixel, opacity);
}
