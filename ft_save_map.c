/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:19:30 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 13:59:10 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_border(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y))
	{
		x = 0;
		while (x < (data->size_x))
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1' &&
				data->map[y][x] != 'C' && data->map[y][x] != 'P' &&
				data->map[y][x] != 'E')
				ft_error("Error\nfor map '0','1','C','P','E' are valid\n");
			else if ((y == 0 || x == 0) && data->map[y][x] != '1')
				ft_error("Error\nmap has to be surrounded by walls\n");
			else if ((y == (data->size_y - 1)
					|| x == (data->size_x - 1))
				&& data->map[y][x] != '1')
				ft_error("Error\nmap has to be surrounded by walls\n");
			x++;
		}
		y++;
	}
}

void	ft_check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;

	data->collectible = 0;
	y = 0;
	exit = 0;
	player = 0;
	while (data->map[y] && data->map)
	{
	exit += ft_count(data->map[y], 'E');
		player += ft_count(data->map[y], 'P');
		data->collectible += ft_count(data->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_error("Error\nonly valid map if one player is contained\n");
	if (exit == 0)
		ft_error("Error\nonly valid map if at least one exit is contained\n");
	if (data->collectible == 0)
		ft_error("Error\nonly valid map if at least one collec is contained\n");
}

void	ft_check_map_demention(t_data *data)
{
	int	i;
	int	first_length;

	i = 0;
	first_length = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if ((first_length != ft_strlen(data->map[i])))
		{
			ft_printstr("Error\n: fix your wall !");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_save_map(t_data *data, char **argv)
{
	char	*buff;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	buff = get_next_line(fd);
	data->map = malloc(sizeof(char *) * (data->size_y + 1));
	while (buff)
	{
		data->map[i] = buff;
		buff = get_next_line(fd);
		i++;
	}
	free(buff);
	data->map[i] = NULL;
	close(fd);
	ft_check_map_demention(data);
	ft_check_content(data);
	ft_check_border(data);
}
