/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:38:24 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 02:38:51 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook_bonus(int keycode, t_data *data)
{
	data->x = 0;
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		ft_move_bonus(data, 'y', UP);
	else if (keycode == A)
		ft_move_bonus(data, 'x', LEFT);
	else if (keycode == S)
		ft_move_bonus(data, 'y', DOWN);
	else if (keycode == D)
		ft_move_bonus(data, 'x', RIGHT);
	if (data->map[data->p_y][data->p_x] == 'E')
		ft_win(data);
	return (0);
}
