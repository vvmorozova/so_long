/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:38:12 by eward             #+#    #+#             */
/*   Updated: 2022/04/22 13:38:14 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_str(t_game_data *map_data, size_t i, t_checkmap *ch_data)
{
	char	allowed[5];
	int		j;

	j = 0;
	ft_memcpy(allowed, "01CEP", 5);
	if (*(*((map_data->map) + i)) != '1' || *(*((map_data->map) + i)
			+ map_data->width - 1) != '1')
		my_error("Holes in walls! ಠ~ಠ\n");
	while (j < map_data->width)
	{
		if (!ft_strchr(allowed, *(*((map_data->map) + i) + j)))
			my_error("Wrong symbols in map! ಠ_ಠ\n");
		if (*(*((map_data->map) + i) + j) == 'P')
		{
			map_data->imgs.cow->pose_x = i;
			map_data->imgs.cow->pose_y = j;
			ch_data->player++;
		}
		if (*(*((map_data->map) + i) + j) == 'E')
			ch_data->out++;
		if (*(*((map_data->map) + i) + j) == 'C')
			map_data->max_score++;
		j++;
	}
}

void	check_map(t_game_data *map_data, t_checkmap *ch_data)
{
	int	i;
	int	j;
	int	len_i;

	i = -1;
	while (++i < map_data->height)
	{
		len_i = ft_strlen(*(map_data->map + i)) - 1;
		if (map_data->width != len_i)
			my_error("Croocked map! o_O\n");
		if (i == 0 || i == map_data->height - 1)
		{
			j = -1;
			while (++j < len_i)
				if (ft_strncmp(((map_data->map)[i] + j), "1", 1))
					my_error("Holes in walls! _ಠ~ಠ\n");
		}
		else
			check_str(map_data, i, ch_data);
	}
}

void	map_parcer(t_game_data *map_data)
{
	t_checkmap	ch_data;

	ch_data.player = 0;
	ch_data.out = 0;
	map_data->max_score = 0;
	map_data->width = ft_strlen(*(map_data->map)) - 1;
	check_map(map_data, &ch_data);
	if (ch_data.player != 1)
		my_error("No player or more than 1 on the map! O_O\n");
	if (ch_data.out != 1)
		my_error("No exit or more than one exit! =_=\n");
	if (map_data->max_score < 1)
		my_error("No collectibles on the map! -_-\n");
	ft_printf("Map is ok!\n");
}

void	how_many_strs(char *file_name, t_game_data *map_data)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		my_error("Something wrong with map *_*\n");
	map_data->height = -1;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		map_data->height++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

void	read_map(char *file_name, t_game_data *map_data)
{
	char	*str;
	int		fd;
	int		i;

	how_many_strs(file_name, map_data);
	map_data->map = (char **)malloc(map_data->height * sizeof(char *) + 1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		my_error("Something wrong with map *_*\n");
	str = get_next_line(fd);
	i = 0;
	while (i < map_data->height)
	{
		*(map_data->map + i) = (char *)malloc(ft_strlen(str) + 1);
		ft_memmove(*(map_data->map + i), str, ft_strlen(str) + 1);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	map_parcer(map_data);
	if (close(fd) < 0)
		my_error("Mistake occured while closing file .-.\n");
}
