/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:30:40 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 02:33:11 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_creat_map_help(t_data *data)
{
	while (data->y < data->size_y)
	{
		if (data->map[data->y][data->x] == 'P')
			ft_put_player(data, data->img->player);
		if (data->map[data->y][data->x] == 'C')
			ft_put_object(data, data->img->collectible);
		if (data->map[data->y][data->x] == 'E')
			ft_put_object(data, data->img->exit);
		if (data->map[data->y][data->x] == '0')
			ft_put_object(data, data->img->background);
		if (data->x < data->size_x)
			data->x++;
		else
		{
			data->y++;
			data->x = 0;
		}
	}
	data->x = 0;
	data->y = 0;
}

void	ft_creat_map(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->y < data->size_y)
	{
		if (data->map[data->y][data->x] == '1')
			ft_put_object(data, data->img->wall);
		if (data->x < data->size_x)
			data->x++;
		else
		{
			data->y++;
			data->x = 0;
		}
	}
	data->x = 0;
	data->y = 0;
	ft_creat_map_help(data);
}
