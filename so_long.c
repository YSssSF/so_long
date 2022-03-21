/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:35:00 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 15:36:16 by yel-aoun         ###   ########.fr       */
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
	ft_creat_map(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	data.collect = 0;
	data.counter = 0;
	ft_input_and_window(&data, argc, argv);
	ft_save_map(&data, argv);
	data.mlx = mlx_init();
	ft_init(&data, &img);
	data.win = mlx_new_window(data.mlx, data.size_x * 64,
			data.size_y * 64, "./so_long");
	ft_create_game(&data);
	mlx_loop(data.mlx);
}
