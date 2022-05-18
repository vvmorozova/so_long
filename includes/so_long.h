/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:04:04 by eward             #+#    #+#             */
/*   Updated: 2022/03/24 14:04:06 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h> 
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define MLX_ERROR 1
# define ANIMATION_SPEED 20

typedef struct s_player{
	void	**player;
	size_t	pose_x;
	size_t	pose_y;
}	t_player;

typedef struct s_image{
	t_player	*cow;
	void		**pear;
	void		*exit;
	void		*wall;
	void		*grass;
}	t_image;

typedef struct s_game_data{
	int		mouth;
	int		dir;
	int		steps;
	int		konami;
	int		konami_arr[10];
	char	**map;
	int		height;
	int		width;
	t_image	imgs;
	size_t	max_score;
	void	*mlx_ptr;
	void	*window;
	int		game_over;
	int		pic_size;
}	t_game_data;

typedef struct s_ch{
	int		out;
	int		player;
}	t_checkmap;

unsigned long	ft_strlen(char *s);
void			*ft_memmove(void *dst, const void *src, unsigned long len);
void			my_error(char *msg);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, unsigned long n);
void			read_map(char *file_name, t_game_data *map_data);
void			open_close_window(t_game_data	*map_data);
void			init_window(t_game_data	*map_data);
void			init_all_pics(t_game_data *map_data);
void			put_textures_to_field(t_game_data *map_data);
int				key_hook(int keycode, t_game_data *map_data);
void			my_put_image_window(t_game_data *map_data, int x, int y);
int				close_window(t_game_data *map_data);
int				check(t_game_data *map_data, int i, int j);
char			*ft_itoa(int n);
void			generate_enemy(t_game_data *map_data);
int				update_enemy(t_game_data *map_data);
void			check_konami(int keycode, t_game_data *map_data);
#endif
