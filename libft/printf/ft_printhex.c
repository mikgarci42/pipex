/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:06:59 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:33 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_printhexa(t_flags **flag, va_list ap)
{
	unsigned int	hex;
	int				len;
	char			str[16];
	int				a;

	hex = va_arg(ap, unsigned int);
	len = ft_conthex(hex);
	flag[0]->len = len;
	ft_printhexa3(flag, len);
	a = ft_writepoint((uintptr_t)hex, str);
	if (hex == 0)
	{
		if (flag[0]->isprecision == 1 && flag[0]->precision <= 0)
		{
			flag[0]->len = 0;
			a = 0;
			if (flag[0]->width > 0)
				len -= 1;
			flag[0]->zero = 0;
		}
	}
	ft_printfhex2(flag, hex, len);
	ft_writehex(flag, str, len, a);
	ft_printfhex1(flag, hex, len);
}

void	ft_hex0x(t_flags **flag)
{
	if (flag[0]->hexb == 1)
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}

void	ft_writehex(t_flags **flag, char	*str, int len, int a)
{
	int	cont;

	cont = 0;
	if (flag[0]->precision > len)
		ft_putspace(flag[0]->precision - len, '0');
	while (--a >= 0)
	{
		if (flag[0]->hexb)
			str[a] = ft_toupper(str[a]);
		write(1, &str[a], 1);
	}
	return ;
}

void	ft_smallhex(t_flags**flag, int len, uintptr_t hex)
{
	int	cont;

	cont = len;
	if (len < flag[0]->precision)
		cont = flag[0]->precision;
	if (flag[0]->hastag && hex)
		cont += 2;
	if (flag[0]->zero == 1 && flag[0]->precision == -1 && flag[0]->minus == -1)
	{
		if (flag[0]->hastag && flag[0]->minus == -1 && hex)
		{
			flag[0]->hastag = 0;
			ft_hex0x(flag);
		}
		ft_putspace(flag[0]->width - cont, '0');
	}
	else
	{
		ft_putspace(flag[0]->width - cont, ' ');
		if (flag[0]->hastag && flag[0]->minus == -1 && hex)
		{
			flag[0]->hastag = 0;
			ft_hex0x(flag);
		}
	}
}
