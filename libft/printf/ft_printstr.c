/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:45 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:57:02 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	ft_strwrite(char *str, int len)
{
	int	cont;

	cont = 0;
	while (str[cont] && cont < len)
	{
		write(1, &str[cont], 1);
		cont++;
	}
	return ;
}

void	ft_printfstr(t_flags **flag, va_list ap)
{
	char	*str;
	int		len;
	int		a;

	a = 0;
	str = va_arg(ap, char *);
	if (!str && flag[0]->minusprecision)
		flag[0]->precision = 6;
	if (!str)
	{
		str = ft_strdup("(null)");
		a = 1;
	}
	len = ft_strlen(str);
	flag[0]->len = len;
	ft_printfstr2(flag, len, str, a);
}

void	ft_printchar(t_flags **flag, va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	flag[0]->len = 1;
	if (flag[0]->minus == -1 && flag[0]->width > 1)
		ft_putspace(flag[0]->width - 1, ' ');
	write(1, &c, 1);
	if (flag[0]->minus == 1 && flag[0]->width > 1)
		ft_putspace(flag[0]->width - 1, ' ');
}

void	ft_printpoint(t_flags **flag, va_list ap)
{
	uintptr_t	point;
	int			len;
	char		str[16];
	int			a;

	point = va_arg(ap, uintptr_t);
	len = ft_contpoint(point);
	len = ft_printpoint3(flag, len, point);
	a = ft_writepoint(point, str);
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus != 1)
		ft_smallhex(flag, len, point);
	write(1, "0x", 2);
	if (flag[0]->precision > len)
		ft_putspace(flag[0]->precision - len, '0');
	if (point != 0 || flag[0]->precision > 0)
	{	
		while (--a >= 0)
			write(1, &str[a], 1);
	}
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus == 1)
		ft_smallhex(flag, len, point);
}

int	ft_conthex(unsigned int hex)
{
	int	len;

	len = 1;
	while (hex >= 16)
	{
		hex /= 16;
		len++;
	}
	return (len);
}
