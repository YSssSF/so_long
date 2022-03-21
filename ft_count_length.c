/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:07:27 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 13:58:07 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_length(int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap File empty\n");
	i = ft_strlen(line);
	free(line);
	return (i);
}
