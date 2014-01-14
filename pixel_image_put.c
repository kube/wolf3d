/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_image_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 22:34:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/14 18:03:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void				pixel_to_image_alpha(t_mlx *mlx,
						unsigned int x, unsigned int y, int color)
{
	unsigned int	i;

	if (x >= mlx->win_width)
		return ;
	i = mlx->win_width * y + x;
	if (i < mlx->win_width * mlx->win_height)
		mlx->data[i] = blend_colors(env->data[i], color, (opacity + 1) / 2);
}

void				pixel_to_image(t_mlx *mlx,
						unsigned int x, unsigned int y, int color)
{
	unsigned int	i;

	if (x >= mlx->win_width)
		return ;
	i = mlx->win_width * y + x;
	if (i < mlx->win_width * mlx->win_height)
		mlx->data[i] = color;
}