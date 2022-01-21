/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:45 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:46 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_numlen(long int num, t_flags **flag)
{
	long	cont;
	int		a;

	a = 0;
	cont = 1;
	if (num == 0 && ((flag[0]->width != -1 && flag[0]->zero)
			&& flag[0]->precision != -1))
	{
		return (0);
	}
	if (num < 0)
	{
		num = num * (-1);
		cont++;
		a = 1;
	}
	while (num > 9)
	{
		num = num / 10;
		cont++;
	}
	if (flag[0]->precision == cont && a)
		cont--;
	return (cont);
}

void	ft_putspace(long int len, char c)
{
	while (len-- > 0)
		write(1, &c, 1);
}

void	ft_small(t_flags **flag, int len, int a)
{
	int	cont;

	cont = len;
	if (len < flag[0]->precision)
		cont = flag[0]->precision;
	if (flag[0]->num < 0 && ((flag[0]->precision > flag[0]->width)
			|| (flag[0]->zero == 1 && flag[0]->precision == -1)))
	{
		flag[0]->num *= -1;
		write(1, "-", 1);
	}
	if (flag[0]->plus && !flag[0]->unsin && flag[0]->num >= 0
		&& flag[0]->zero == 1 && flag[0]->isprecision == -1)
	{
		flag[0]->plus = 0;
		write(1, "+", 1);
	}
	if (flag[0]->zero == 1 && (flag[0]->precision > flag[0]->width)
		&& flag[0]->num < 0)
	{
		ft_putspace(flag[0]->width - cont, '0');
	}
	else
		ft_small2(flag, cont, a, len);
	return ;
}

void	ft_printfnum(t_flags **flag, va_list ap)
{
	long int	num;
	long		len;
	int			a;

	a = 0;
	if (flag[0]->unsin)
		num = va_arg(ap, unsigned int);
	else
		num = va_arg(ap, int);
	flag[0]->num = num;
	len = ft_numlen(num, flag);
	ft_printfnum3(flag, num, len);
	if (num < 0)
		a = 1;
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus != 1)
		ft_small(flag, len, a);
	ft_putnumd(flag, num);
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus == 1)
		ft_small(flag, len, a);
}

void	ft_putnumd(t_flags **flag, long int num)
{
	long	len;
	int		cont;

	cont = 0;
	len = ft_numlen(num, flag);
	if (flag[0]->plus && !flag[0]->unsin && flag[0]->num >= 0)
	{
		flag[0]->plus = 0;
		write(1, "+", 1);
	}
	if (flag[0]->precision > len)
	{
		if (flag[0]->num < 0)
		{
			write(1, "-", 1);
			num = num * -1;
			flag[0]->num = -flag[0]->num;
		}
		len = ft_numlen(num, flag);
		ft_putspace(flag[0]->precision - len, '0');
	}
	ft_putnumd2(flag, cont, num, len);
	return ;
}
