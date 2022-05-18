/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:07:09 by eward             #+#    #+#             */
/*   Updated: 2022/05/05 20:07:10 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_game_data *map_data)
{
	char	*str;
	int		i;
	int		j;

	i = map_data->imgs.cow->pose_x;
	j = map_data->imgs.cow->pose_y;
	if (map_data->map[i - 1][j] - '1' != 0 && check(map_data, i - 1, j))
	{
		map_data->map[i - 1][j] = 'P';
		map_data->map[i][j] = '0';
		my_put_image_window(map_data, i, j);
		my_put_image_window(map_data, i - 1, j);
		map_data->imgs.cow->pose_x = i - 1;
		my_put_image_window(map_data, 0, 0);
		str = ft_itoa(++(map_data->steps));
		mlx_string_put(map_data->mlx_ptr, map_data->window,
			24, 24, 2162250, str);
		ft_printf("Number of steps: %d\n", map_data->steps);
		free(str);
		return (1);
	}
	return (0);
}

int	move_down(t_game_data *map_data)
{
	char	*str;
	int		i;
	int		j;

	i = map_data->imgs.cow->pose_x;
	j = map_data->imgs.cow->pose_y;
	if (map_data->map[i + 1][j] - '1' != 0 && check(map_data, i + 1, j))
	{
		map_data->map[i + 1][j] = 'P';
		map_data->map[i][j] = '0';
		my_put_image_window(map_data, i, j);
		my_put_image_window(map_data, i + 1, j);
		map_data->imgs.cow->pose_x = i + 1;
		my_put_image_window(map_data, 0, 0);
		str = ft_itoa(++(map_data->steps));
		mlx_string_put(map_data->mlx_ptr, map_data->window,
			24, 24, 2162250, str);
		ft_printf("Number of steps: %d\n", map_data->steps);
		free(str);
		return (1);
	}
	return (0);
}

int	move_left(t_game_data *map_data)
{
	char	*str;
	int		i;
	int		j;

	i = map_data->imgs.cow->pose_x;
	j = map_data->imgs.cow->pose_y;
	map_data->dir = 1;
	if (map_data->map[i][j - 1] - '1' != 0 && check(map_data, i, j - 1))
	{
		map_data->map[i][j - 1] = 'P';
		map_data->map[i][j] = '0';
		my_put_image_window(map_data, i, j);
		my_put_image_window(map_data, i, j - 1);
		map_data->imgs.cow->pose_y = j - 1;
		my_put_image_window(map_data, 0, 0);
		str = ft_itoa(++(map_data->steps));
		mlx_string_put(map_data->mlx_ptr, map_data->window,
			24, 24, 2162250, str);
		ft_printf("Number of steps: %d\n", map_data->steps);
		free(str);
		return (1);
	}
	return (0);
}

int	move_right(t_game_data *map_data)
{
	char	*str;
	int		i;
	int		j;

	i = map_data->imgs.cow->pose_x;
	j = map_data->imgs.cow->pose_y;
	map_data->dir = 0;
	if (map_data->map[i][j + 1] - '1' != 0 && check(map_data, i, j + 1))
	{
		map_data->map[i][j + 1] = 'P';
		map_data->map[i][j] = '0';
		my_put_image_window(map_data, i, j);
		my_put_image_window(map_data, i, j + 1);
		map_data->imgs.cow->pose_y = j + 1;
		my_put_image_window(map_data, 0, 0);
		str = ft_itoa(++(map_data->steps));
		mlx_string_put(map_data->mlx_ptr, map_data->window,
			24, 24, 2162250, str);
		ft_printf("Number of steps: %d\n", map_data->steps);
		free(str);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_game_data *map_data)
{
	int	i;
	int	j;

	i = map_data->imgs.cow->pose_x;
	j = map_data->imgs.cow->pose_y;
	check_konami(keycode, map_data);
	if (keycode == 13 || keycode == 126)
		move_up(map_data);
	if (keycode == 0 || keycode == 123)
		move_left(map_data);
	if (keycode == 1 || keycode == 125)
		move_down(map_data);
	if (keycode == 2 || keycode == 124)
		move_right(map_data);
	if (keycode == 53 || map_data->game_over != 0)
		close_window(map_data);
	return (0);
}
