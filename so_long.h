/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:36:25 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 17:19:32 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img {
	void	*player;
	void	*player2;
	void	*collectible;
	void	*collectible2;
	void	*background;
	void	*enemy;
	void	*enemy2;
	void	*exit;
	void	*wall;
}		t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		en;
	int		en2;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		st;
	int		st2;
	int		collectible;
	int		collect;
	int		counter;
	int		size_x;
	int		size_y;
	void	*background;
	void	*object;
	void	*player;
	char	**map;
	t_img	*img;
}		t_data;

void	ft_input_and_window(t_data *data, int argc, char **argv);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strdup_demo(char *s1, int d);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strjoin_ft(char *s1, char *s2, int s);
int		ft_count_length(int fd);
int		ft_count_line(int fd);
void	ft_save_map(t_data *data, char **argv);
void	*ft_memmove(void	*dst, const void	*src, size_t	len);
void	ft_error(char *str);
void	ft_create_game(t_data *data);
void	ft_init(t_data *data, t_img *img);
void	ft_creat_map(t_data *data);
void	ft_put_object(t_data *data, void *object);
void	ft_put_player(t_data *data, void *player);
int		ft_key_hook(int keycode, t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	ft_move_bonus(t_data *data, char pos, int dir);
int		ft_exit(t_data *data);
void	ft_player_move(t_data *data);
void	ft_win(t_data *data);
void	ft_collect(t_data *data);
char	*ft_itoa(int n);
int		ft_animations(t_data *data);
void	ft_lose(t_data *data);
void	ft_creat_map_bonus(t_data *data);
void	ft_creat_map(t_data *data);
int		ft_key_hook_bonus(int keycode, t_data *data);
void	ft_save_map_bonus(t_data *data, char **argv);
void	ft_init_bonus(t_data *data, t_img *img);
int		ft_count(char *str, char c);
void	ft_object_animation2(t_data *data, void *obj1, void *obj2, char y);

#endif