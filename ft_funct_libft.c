/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:33:15 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/20 15:18:19 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
				{
					return ((char *)haystack + i);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_count(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if (str[i] == c)
			x++;
		i++;
	}
	return (x);
}
