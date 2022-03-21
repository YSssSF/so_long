/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:36:34 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 02:38:14 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void	ft_input_and_window(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_error("Error\nUsage: './so_long mappath/mapname.ber'\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error("Error\nmap has to be .ber\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nInvalid map_path/map\n");
	data->size_x = ft_count_length(fd);
	data->size_y = ft_count_line(fd);
	if (data->size_x < data->size_y)
		ft_error("Error\n: The map must be rectangular ");
	close(fd);
}
