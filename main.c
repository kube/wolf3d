/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kube <kube@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:16:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/12 02:08:48 by kube             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			display_map(t_map_square ***map)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%d ", map[j][i]->type);
			i++;
		}
		printf("\n");
		j++;
	}
}

int					main(int argc, char **argv)
{
	t_env			env;

	(void)argc;
	(void)argv;
	(void)display_map;

	load_map(&env, "maps/example.wolfmap");
	display_map(env.map);
	return (0);
}
