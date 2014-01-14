/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:18:07 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/14 22:28:15 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
// # include <guava.h>
# include <libft.h>
# include <get_next_line.h>

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct				s_point
{
	float					x;
	float					y;
	float					z;
}							t_point;

typedef struct				s_vector
{
	t_point					*a;
	t_point					*b;
}							t_vector;


typedef struct				s_pressed_keys
{
	int						up;
	int						down;
	int						left;
	int						right;
}							t_pressed_keys;

typedef struct				s_map_square
{
	int						type;
	int						texture;
	int						color;
	int						height;
	int						opacity;
	int						reflexion;
}							t_map_square;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	int						*data;
	int						bpp;
	int						size_line;
	int						endian;
	unsigned int			win_width;
	unsigned int			win_height;
}							t_mlx;

struct						s_params
{
	int						blured;
	int						antialiased;
};

typedef	struct				s_env
{
	t_map_square
	t_map_square			***map;
	int						map_height;
	int						map_width;
	t_mlx					mlx;
	struct s_params			params;
	t_pressed_keys			pressed_keys;
	t_point					position;
}							t_env;

void				load_map(t_env *env, char *file_name);

#endif
