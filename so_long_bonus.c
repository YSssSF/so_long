/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:23:47 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:06:22 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("You gave up :(\n Is the map to hard for you?\n");
	exit(EXIT_SUCCESS);
}

void	ft_create_game(t_data *data)
{
	char	*moves;

	moves = "0";
	ft_creat_map_bonus(data);
	mlx_string_put(data->mlx, data->win, 0, 0, 0xff0000, "moves:");
	mlx_string_put(data->mlx, data->win, 70, 0, 0xff0000, moves);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook_bonus, data);
	mlx_loop_hook(data->mlx, ft_animations, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	data.st = 0;
	data.st2 = 0;
	data.en = 0;
	data.collect = 0;
	data.counter = 0;
	ft_input_and_window(&data, argc, argv);
	ft_save_map_bonus(&data, argv);
	data.mlx = mlx_init();
	ft_init_bonus(&data, &img);
	data.win = mlx_new_window(data.mlx, data.size_x * 64,
			data.size_y * 64, "./so_long_bonus");
	ft_create_game(&data);
	mlx_loop(data.mlx);
}
