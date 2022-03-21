/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:22:25 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 13:42:27 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_en2(t_data *data, void *obj2, char y)
{
	if (data->map[data->y][data->x] == y)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->x * 64, data->y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			obj2, data->x * 64, data->y * 64);
		data->st = 0;
		data->st2 = 0;
	}
	if (data->x < data->size_x)
		data->x++;
	else
	{
		data->y++;
		data->x = 0;
	}
}

void	ft_en1(t_data *data, void *obj1, char y)
{
	if (data->map[data->y][data->x] == y)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->x * 64, data->y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			obj1, data->x * 64, data->y * 64);
		data->st++;
	}
	if (data->x < data->size_x)
		data->x++;
	else
	{
		data->y++;
		data->x = 0;
	}
}

void	ft_object_animation(t_data *data, void *obj1, void *obj2, char y)
{
	if (data->st == 7000)
	{
		while (data->y < data->size_y)
			ft_en1(data, obj1, y);
		data->x = 0;
		data->y = 0;
	}
	else
		data->st++;
	if (data->st2 == 14000)
	{
		while (data->y < data->size_y)
			ft_en2(data, obj2, y);
		data->x = 0;
		data->y = 0;
	}
	else
		data->st2++;
}

void	ft_player_animation(t_data *data, void *pl1, void *pl2)
{
	if (data->st == 4000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->p_x * 64, data->p_y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			pl1, data->p_x * 64, data->p_y * 64);
		data->st++;
	}
	else
		data->st++;
	if (data->st2 == 8000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, data->p_x * 64, data->p_y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			pl2, data->p_x * 64, data->p_y * 64);
		data->st = 0;
		data->st2 = 0;
	}
	else
		data->st2++;
}

int	ft_animations(t_data *data)
{
	ft_player_animation(data, data->img->player, data->img->player2);
	ft_object_animation(data, data->img->enemy,
		data->img->enemy2, 'X');
	return (0);
}
