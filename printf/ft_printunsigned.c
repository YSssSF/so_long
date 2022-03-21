/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:55:32 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:55:33 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int v)
{
	long int	x;

	x = v;
	if (x >= 10)
		ft_printunsigned(x / 10);
	ft_printchar((x % 10) + 48);
	return (ft_cal_dec(v));
}
