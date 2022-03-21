/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:52:38 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:52:39 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int d)
{
	long long	s;

	s = d;
	if (s < 0)
	{
		ft_printchar('-');
		s *= -1;
	}
	if (s >= 10)
		ft_printdec(s / 10);
	ft_printchar((s % 10) + 48);
	return (ft_cal_dec(d));
}
