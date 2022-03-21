/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:43 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 13:40:28 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_en2(t_data *data, void *obj2, char y)
{
	if (data->map[data->yy][data->xx] == y)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->x * 64, data->y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			obj2, data->x * 64, data->y * 64);
		data->stt = 0;
		data->stt2 = 0;
	}
	if (data->xx < data->size_x)
		data->xx++;
	else
	{
		data->yy++;
		data->xx = 0;
	}
}

void	ft_en1(t_data *data, void *obj1, char y)
{
	if (data->map[data->yy][data->xx] == y)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->xx * 64, data->yy * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			obj1, data->xx * 64, data->yy * 64);
		data->stt++;
	}
	if (data->xx < data->size_x)
		data->xx++;
	else
	{
		data->yy++;
		data->xx = 0;
	}
}

void	ft_object_animation2(t_data *data, void *obj1, void *obj2, char y)
{
	if (data->stt == 7000)
	{
		while (data->yy < data->size_y)
		{
			ft_en1(data, obj1, y);
		}
		data->xx = 0;
		data->yy = 0;
	}
	else
		data->stt++;
	if (data->stt2 == 14000)
	{
		while (data->yy < data->size_y)
			ft_en2(data, obj2, y);
		data->xx = 0;
		data->yy = 0;
	}
	else
		data->stt2++;
}
