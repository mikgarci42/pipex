/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumesrc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:59:19 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:52 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_small2(t_flags **flag, int cont, int a, long len)
{
	if ((a && flag[0]->precision > len)
		|| (flag[0]->minusprecision && flag[0]->num == 0))
		cont++;
	if (flag[0]->zero == 1 && flag[0]->precision == -1
		&& flag[0]->minus == -1 && flag[0]->isprecision == -1)
		ft_putspace(flag[0]->width - cont, '0');
	else
		ft_putspace(flag[0]->width - cont, ' ');
}

void	ft_putnumd2(t_flags **flag, int cont, long int num, long len)
{
	if (flag[0]->isprecision && flag[0]->precision == 0 && num == 0)
	{
		if (flag[0]->minusprecision)
		{
			flag[0]->len += 1;
			write(1, "0", 1);
		}
		cont = 0;
	}
	else
	{
		if (flag[0]->num < 0)
		{
			if (flag[0]->precision <= len)
				write(1, "-", 1);
			num *= -1;
			flag[0]->num = -flag[0]->num;
		}
		if ((len > 0 && flag[0]->printnum) || (num == 0
				&& flag[0]->isprecision == -1
				&& (flag[0]->width == -1 && flag[0]->printnum)))
			ft_putnbr(flag[0]->num, 1);
	}
}

void	ft_printfnum2(t_flags **flag, long int num, long len)
{
	if (flag[0]->space && !flag[0]->unsin
		&& flag[0]->num >= 0 && !flag[0]->plus)
	{
		write(1, " ", 1);
		flag[0]->len += 1;
		if (flag[0]->width > len)
		{
			if (flag[0]->width > len + 1)
				flag[0]->wii += 1;
			flag[0]->width -= 1;
		}
	}
	if (num == 0)
	{
		if (flag[0]->isprecision == 1 && flag[0]->precision == -1)
		{
			flag[0]->printnum = 0;
			if (flag[0]->width > 0)
			{
				flag[0]->wii -= 1;
				flag[0]->width += 1;
				flag[0]->zero = 0;
			}
		}	
	}	
}

void	ft_printfnum3(t_flags **flag, long int num, long len)
{
	if (flag[0]->precision > len)
		flag[0]->len = flag[0]->precision;
	else
		flag[0]->len = len;
	if (num < 0 && flag[0]->precision > len)
		flag[0]->len += 1;
	if (flag[0]->plus && !flag[0]->unsin && flag[0]->num >= 0)
	{
		if (flag[0]->width > len)
		{
			flag[0]->width -= 1;
			flag[0]->wii += 1;
		}
		flag[0]->len += 1;
	}
	ft_printfnum2(flag, num, len);
	if ((!flag[0]->plus && num == 0) && (flag[0]->precision == 0
			|| (flag[0]->isprecision == 1 && flag[0]->precision == -1)))
		flag[0]->len = 0;
}
