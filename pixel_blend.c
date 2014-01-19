/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:28:55 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/19 20:27:34 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <layer.h>
#include <libft.h>
#include <stdlib.h>

t_pixel			blend_pixels(t_pixel *a, t_pixel *b, float opacity)
{
	t_pixel		c;

	if (opacity > 1)
		opacity = 1;
	if (opacity <= 0 || b->a == 0)
		return (*a);
	else if ((b->a == 255 || a->a == 0) && opacity == 1)
		return (*b);
	else if (a->a < 255)
	{
		b->a *= opacity;
		c.a = a->a + (1.0 - a->a) * b->a;
		c.r = (a->r * a->a * (255 - b->a) + b->r * b->a) / c.a;
		c.g = (a->g * a->a * (255 - b->a) + b->g * b->a) / c.a;
		c.b = (a->b * a->a * (255 - b->a) + b->b * b->a) / c.a;
	}
	else
	{
		b->a *= opacity;
		c.a = 255;
		c.r = (a->r * (255 - b->a) + b->r * b->a) / 255;
		c.g = (a->g * (255 - b->a) + b->g * b->a) / 255;
		c.b = (a->b * (255 - b->a) + b->b * b->a) / 255;
	}
	return (c);
}
