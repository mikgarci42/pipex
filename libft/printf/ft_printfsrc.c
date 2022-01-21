/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfsrc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:44:36 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:25 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	ft_printfstr2(t_flags **flag, int len, char *str, int a)
{
	if (flag[0]->isprecision == 1 && flag[0]->precision == -1)
		flag[0]->precision = 0;
	if (flag[0]->precision < len && flag[0]->precision >= 0)
	{
		len = flag[0]->precision;
		flag[0]->len = flag[0]->precision;
	}
	if (flag[0]->minus == -1 && flag[0]->width > len)
		ft_putspace(flag[0]->width - len, ' ');
	ft_strwrite(str, len);
	if (flag[0]->minus == 1 && flag[0]->width > len)
		ft_putspace(flag[0]->width - len, ' ');
	if (a)
		free(str);
}

void	ft_printpoint2(t_flags **flag)
{
	if (flag[0]->precision == -1 && flag[0]->isprecision == -1)
		flag[0]->precision = 1;
	if (flag[0]->isprecision == 1 && flag[0]->precision == -1)
	{
		flag[0]->zero = 0;
		if (flag[0]->width > 0)
			flag[0]->width += 1;
		else
			flag[0]->len -= 1;
	}
	if (flag[0]->isprecision == 1 && flag[0]->width == -3)
	{
		if (flag[0]->precision == 0)
			flag[0]->len -= 1;
	}
	if (flag[0]->width >= -2 && flag[0]->precision >= 0)
	{
		if (flag[0]->precision == 0 && flag[0]->width < 1)
			flag[0]->len -= 1;
		if (flag[0]->precision == 0 && flag[0]->width >= 1)
			flag[0]->width += 1;
	}
}

int	ft_printpoint3(t_flags **flag, int len, uintptr_t point)
{
	if (point == 0)
		len = 3;
	flag[0]->len = len;
	if (len > 0)
		len -= 2;
	if (flag[0]->precision > len && flag[0]->precision >= 2
		&& (flag[0]->precision + 2) > (flag[0]->width))
		flag[0]->len = flag[0]->precision + 2;
	else if (flag[0]->width > flag[0]->len && flag[0]->width > 2)
		flag[0]->len = flag[0]->width;
	flag[0]->width -= 2;
	if (point == 0)
		ft_printpoint2(flag);
	return (len);
}
