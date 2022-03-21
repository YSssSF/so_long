/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:26:57 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 02:28:08 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_init_help(t_data *data)
{
	int		img_width;
	int		img_height;

	data->img->exit = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
			&img_width, &img_height);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"./images/back.xpm",
			&img_width, &img_height);
	data->img->wall = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm",
			&img_width, &img_height);
	data->img->enemy = mlx_xpm_file_to_image(data->mlx, "./images/kaido1.xpm",
			&img_width, &img_height);
	data->img->enemy2 = mlx_xpm_file_to_image(data->mlx, "./images/kk.xpm",
			&img_width, &img_height);
}

void	ft_init_bonus(t_data *data, t_img *img)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	data->img = img;
	data->img->player = mlx_xpm_file_to_image(data->mlx, "./images/lp.xpm",
			&img_width, &img_height);
	data->img->player2 = mlx_xpm_file_to_image(data->mlx, "./images/lp2.xpm",
			&img_width, &img_height);
	data->img->collectible = mlx_xpm_file_to_image(data->mlx,
			"./images/fruit.xpm",
			&img_width, &img_height);
	data->img->collectible2 = mlx_xpm_file_to_image(data->mlx,
			"./images/fruit2.xpm",
			&img_width, &img_height);
	ft_init_help(data);
}
