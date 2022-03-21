/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:49:54 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/03/21 14:49:55 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(char c);
int	ft_cal_hexa(unsigned long long x);
int	ft_printadd(unsigned long long k);
int	ft_printhexa(long long int x, char c);
int	ft_printstr(char *s);
int	ft_printdec(int d);
int	ft_cal_dec(long long c);
int	ft_printunsigned(unsigned int v);

#endif
