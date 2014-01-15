/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:43:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/15 19:36:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <layer.h>
#include <stdlib.h>
#include <wolf3d.h>
#include <color.h>

t_layer				*create_layer(unsigned int width, unsigned int height,
									int blend_mode)
{
	t_layer			*layer;

	layer = (t_layer*)malloc(sizeof(t_layer));
	layer->width = width;
	layer->height = height;
	layer->blend_mode = blend_mode;
	layer->data = (int*)malloc(width * height * sizeof(int));
	return (layer);
}

/*
**	We'll add other Blend Modes here later
*/

void				apply_layer(t_mlx *mlx, t_layer *layer)
{
	unsigned int	i;
	t_pixel			*dst;
	t_pixel			*src;

	i = 0;
	src = (t_pixel*)layer->data;
	dst = (t_pixel*)mlx->data;
	while (i < mlx->win_height * mlx->win_width)
	{
		dst[i] = blend_pixels(dst[i], src[i], layer->opacity);
		i++;
	}
}
