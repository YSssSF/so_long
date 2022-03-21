/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:39:14 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 02:42:12 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_object(t_data *data, void *object)
{
	int	img_width;
	int	img_height;

	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		data->x * 64, data->y * 64);
	mlx_put_image_to_window(data->mlx, data->win, object,
		data->x * 64, data->y * 64);
}

void	ft_put_player(t_data *data, void *player)
{
	int	img_width;
	int	img_height;

	data->p_x = data->x;
	data->p_y = data->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		data->x * 64, data->y * 64);
	mlx_put_image_to_window(data->mlx, data->win, player,
		(data->p_x * 64), (data->p_y * 64));
}
