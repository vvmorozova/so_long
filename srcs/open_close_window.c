/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:57:53 by eward             #+#    #+#             */
/*   Updated: 2022/05/05 12:57:56 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	init_konami(t_game_data	*map_data)
{
	map_data->konami = 0;
	map_data->konami_arr[0] = 126;
	map_data->konami_arr[1] = 126;
	map_data->konami_arr[2] = 125;
	map_data->konami_arr[3] = 125;
	map_data->konami_arr[4] = 123;
	map_data->konami_arr[5] = 124;
	map_data->konami_arr[6] = 123;
	map_data->konami_arr[7] = 124;
	map_data->konami_arr[8] = 11;
	map_data->konami_arr[9] = 0;
}

int	close_window(t_game_data *map_data)
{
	mlx_destroy_window(map_data->mlx_ptr, map_data->window);
	free(map_data->mlx_ptr);
	if (map_data->game_over == 1)
		ft_printf("You won! You're the most cute lil' calf in the world <3\n");
	else if (map_data->game_over == -1)
		ft_printf("YOU must eat pears, not vise versa! ; ((((\n");
	else
		ft_printf("Bye!!!! :333\n");
	exit(0);
	return (0);
}

void	init_window(t_game_data	*map_data)
{
	map_data->mouth = 0;
	map_data->game_over = 0;
	map_data->steps = 0;
	map_data->dir = 0;
	map_data->mlx_ptr = mlx_init();
	map_data->pic_size = 60;
	init_konami(map_data);
	if (map_data->mlx_ptr == NULL)
		my_error("Minilibx error ;-(\n");
	map_data->window = mlx_new_window(map_data->mlx_ptr,
			map_data->width * map_data->pic_size,
			map_data->height * map_data->pic_size, "SO_LONG");
	if (map_data->window == NULL)
	{
		free(map_data->mlx_ptr);
		free(map_data->window);
		my_error("Minilibx error with window ;3\n");
	}
	mlx_hook(map_data->window, 17, 1L << 17, close_window, map_data);
}
