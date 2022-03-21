/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:03 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:54:04 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(long long int x, char c)
{
	int	hex;

	hex = ft_cal_hexa(x);
	if (x >= 16)
		ft_printhexa(x / 16, c);
	if (c == 'x')
		ft_printchar("0123456789abcdef"[x % 16]);
	if (c == 'X')
		ft_printchar("0123456789ABCDEF"[x % 16]);
	return (hex);
}
