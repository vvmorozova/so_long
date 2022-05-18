/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:28:18 by eward             #+#    #+#             */
/*   Updated: 2022/05/05 13:28:19 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_texture(void **obj, char *path, t_game_data *map_data)
{
	*obj = mlx_xpm_file_to_image(map_data->mlx_ptr, path,
			&(map_data->pic_size), &(map_data->pic_size));
	if (!(*obj))
		my_error("Smth wrong with textures (((((999(((\n");
}

void	init_all_pics(t_game_data *map_data)
{
	init_texture(&(map_data->imgs.grass), "textures/grass.xpm", map_data);
	init_texture(&(map_data->imgs.wall), "textures/wall.xpm", map_data);
	init_texture(&(map_data->imgs.cow->player[0]),
		"textures/base_skin/cow-right.xpm", map_data);
	init_texture(&(map_data->imgs.cow->player[1]),
		"textures/base_skin/cow-left.xpm", map_data);
	init_texture(&(map_data->imgs.cow->player[2]),
		"textures/black_skin/cow-right.xpm", map_data);
	init_texture(&(map_data->imgs.cow->player[3]),
		"textures/black_skin/cow-left.xpm", map_data);
	init_texture(&(map_data->imgs.exit), "textures/exit.xpm", map_data);
	init_texture(&(map_data->imgs.pear[0]), "textures/pear.xpm", map_data);
	init_texture(&(map_data->imgs.pear[1]), "textures/enemy0.xpm", map_data);
	init_texture(&(map_data->imgs.pear[2]), "textures/enemy1.xpm", map_data);
}

void	*temp_is_not_player(t_game_data *map_data, char c)
{
	if (c - '0' == 0)
		return (map_data->imgs.grass);
	if (c - 'V' == 0 && map_data->mouth >= 0 && map_data->mouth
		<= ANIMATION_SPEED)
		return (map_data->imgs.pear[1]);
	if (c - 'V' == 0 && map_data->mouth > ANIMATION_SPEED)
		return (map_data->imgs.pear[2]);
	if (c - '1' == 0)
		return (map_data->imgs.wall);
	if (c - 'E' == 0)
		return (map_data->imgs.exit);
	if (c - 'C' == 0)
		return (map_data->imgs.pear[0]);
	return (0);
}

void	my_put_image_window(t_game_data *map_data, int x, int y)
{
	void	*temp;
	char	c;
	int		mlx_rez;

	c = (map_data->map)[x][y];
	x = x * map_data->pic_size;
	y = y * map_data->pic_size;
	if (c - 'P' == 0)
	{
		if (map_data->konami == -1)
			temp = map_data->imgs.cow->player[map_data->dir + 2];
		else
			temp = map_data->imgs.cow->player[map_data->dir];
	}
	else
		temp = temp_is_not_player(map_data, c);
	mlx_rez = mlx_put_image_to_window(map_data->mlx_ptr, map_data->window,
			map_data->imgs.grass, y, x);
	mlx_rez = mlx_put_image_to_window(map_data->mlx_ptr, map_data->window,
			temp, y, x);
}

void	put_textures_to_field(t_game_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			my_put_image_window(map_data, i, j);
			j++;
		}
		i++;
	}
}
