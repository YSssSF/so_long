/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:51:10 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:51:11 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_add(unsigned long long k)
{
	if (k >= 16)
		ft_print_add(k / 16);
	ft_printchar("0123456789abcdef"[k % 16]);
}

int	ft_printadd(unsigned long long k)
{
	ft_printchar('0');
	ft_printchar('x');
	ft_print_add(k);
	return (ft_cal_hexa(k) + 2);
}
