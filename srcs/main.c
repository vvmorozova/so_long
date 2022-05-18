/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:45:01 by eward             #+#    #+#             */
/*   Updated: 2022/04/22 13:45:03 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	map_data;

	if (argc != 2)
		my_error("Too many or too little args for the program o_O");
	read_map(argv[1], &map_data);
	generate_enemy(&map_data);
	init_window(&map_data);
	init_all_pics(&map_data);
	put_textures_to_field(&map_data);
	my_put_image_window(&map_data, 0, 0);
	ft_printf("Number of steps: %d\n", map_data.steps);
	mlx_string_put(map_data.mlx_ptr, map_data.window, 24, 24, 2162250, "0");
	mlx_loop_hook(map_data.mlx_ptr, update_enemy, &map_data);
	mlx_key_hook(map_data.window, key_hook, &map_data);
	mlx_loop(map_data.mlx_ptr);
}
