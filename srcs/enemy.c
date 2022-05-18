/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:03:17 by eward             #+#    #+#             */
/*   Updated: 2022/05/10 17:03:19 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_enemy(t_game_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (((i == j && i % 2 == 0)
					|| (i == map_data->height - j && i % 2 != 0))
				&& map_data->map[i][j] == '0')
				map_data->map[i][j] = 'V';
			j++;
		}
		i++;
	}
}

int	update_enemy(t_game_data *map_data)
{
	int	i;
	int	j;

	if (map_data->mouth > ANIMATION_SPEED * 2)
		map_data->mouth = 0;
	else
		map_data->mouth++;
	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (map_data->map[i][j] == 'V')
				my_put_image_window(map_data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
