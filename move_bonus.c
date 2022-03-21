/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:28:02 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 15:32:10 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lose(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Opss! \nYou Lose :( \n Try again\n");
	exit(EXIT_SUCCESS);
}

void	ft_player_move(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->player,
		(data->p_x * 64), (data->p_y * 64));
}

void	ft_collect(t_data *data)
{
	data->collect++;
	data->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * 64), (data->p_y * 64));
}

void	ft_move_help_bonus(t_data *data, char pos, int dir)
{
	if (pos == 'y' && data->map[data->p_y + (1 * dir)][data->p_x] == 'E'
		&& data->collect != data->collectible)
		ft_printf("Collect all diamonds before leaving\n");
	else if (pos == 'x' && data->map[data->p_y][data->p_x + (1 * dir)] == 'E'
		&& data->collect != data->collectible)
		ft_printf("Collect all diamonds before leaving\n");
	if (data->map[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	if (data->map[data->p_y][data->p_x] == 'X')
		ft_lose(data);
	ft_player_move(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->wall, (1 * 64), 0);
	mlx_string_put(data->mlx, data->win, 70, 0, 0xff0000,
		ft_itoa(data->counter));
}

void	ft_move_bonus(t_data *data, char pos, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * 64), (data->p_y * 64));
	if (pos == 'y' && data->map[data->p_y + (1 * dir)][data->p_x] != '1'
		&& (data->map[data->p_y + (1 * dir)][data->p_x] != 'E'
		|| data->collect == data->collectible))
	{
		data->counter++;
		data->p_y = data->p_y + (1 * dir);
	}
	else if (pos == 'x' && data->map[data->p_y][data->p_x + (1 * dir)] != '1'
		&& (data->map[data->p_y][data->p_x + (1 * dir)] != 'E'
		|| data->collect == data->collectible))
	{
		data->counter++;
		data->p_x = data->p_x + (1 * dir);
	}
	ft_move_help_bonus(data, pos, dir);
}
