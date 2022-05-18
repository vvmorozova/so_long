/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:44:13 by eward             #+#    #+#             */
/*   Updated: 2022/05/06 12:44:15 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check(t_game_data *map_data, int i, int j)
{
	if (map_data->map[i][j] - 'C' == 0)
		map_data->max_score--;
	if (map_data->map[i][j] - 'E' == 0 && map_data->max_score != 0)
		return (0);
	if (map_data->map[i][j] - 'E' == 0)
		map_data->game_over = 1;
	if (map_data->map[i][j] - 'V' == 0)
		map_data->game_over = -1;
	return (1);
}

void	check_konami(int keycode, t_game_data *map_data)
{
	if (map_data->konami == 9 || map_data->konami == -1)
	{
		map_data->konami = -1;
		return ;
	}
	if (map_data->konami_arr[map_data->konami] == keycode)
		map_data->konami++;
	else
		map_data->konami = 0;
}
