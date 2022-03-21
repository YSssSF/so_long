/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:32:14 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 15:34:51 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_move_help(t_data *data, char pos, int dir)
{
	if (pos == 'y' && data->map[data->p_y + (1 * dir)][data->p_x] == 'E'
		&& data->collect != data->collectible)
		ft_printf("Collect all diamonds before leaving\n");
	else if (pos == 'x' && data->map[data->p_y][data->p_x + (1 * dir)] == 'E'
		&& data->collect != data->collectible)
		ft_printf("Collect all diamonds before leaving\n");
	if (data->map[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	ft_player_move(data);
}

void	ft_move(t_data *data, char pos, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * 64), (data->p_y * 64));
	if (pos == 'y' && data->map[data->p_y + (1 * dir)][data->p_x] != '1'
		&& (data->map[data->p_y + (1 * dir)][data->p_x] != 'E'
		|| data->collect == data->collectible))
	{
		ft_printf("You moved %d moves\n", ++data->counter);
		data->p_y = data->p_y + (1 * dir);
	}
	else if (pos == 'x' && data->map[data->p_y][data->p_x + (1 * dir)] != '1'
		&& (data->map[data->p_y][data->p_x + (1 * dir)] != 'E'
		|| data->collect == data->collectible))
	{
		ft_printf("You moved %d moves\n", ++data->counter);
		data->p_x = data->p_x + (1 * dir);
	}
	ft_move_help(data, pos, dir);
}
