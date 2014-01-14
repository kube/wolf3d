/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:43:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/14 22:28:00 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <layer.h>
#include <stdio.h>

t_layer				*create_layer(unsigned int width, unsigned int height,
									int fusion_mode)
{
	t_layer			*layer;

	layer = (t_layer*)malloc(sizeof(t_layer));
	layer->width = width;
	layer->height = height;
	layer->fusion_mode = fusion_mode;
	return (layer);
}

/* FOR BLENDING ALPHAS */
/* http://stackoverflow.com/questions/3658804/formula-for-alpha-value-when-blending-two-transparent-colors */

/* FOR BLENDING COLORS */
/* http://stackoverflow.com/questions/154079/what-is-the-formula-for-alpha-blending-for-a-number-of-pixels */

void				apply_layer(t_mlx *mlx, t_layer *layer)
{
	int				i;
	t_pixel			*image_current;
	t_pixel			*layer_current;

	i = 0;
	layer_current = (t_pixel*)layer->data;
	image_current = (t_pixel*)mlx->data;
	while (i < mlx->win_height * mlx->win_width)
	{
		image_pixel_put(image_current, );
		i++;
	}
}