/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexautils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:49:11 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:40 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_printhexa3(t_flags **flag, int len)
{
	if (flag[0]->precision > len && flag[0]->precision > flag[0]->width)
		flag[0]->len = flag[0]->precision;
	else if (flag[0]->width > len && flag[0]->precision < flag[0]->width)
		flag[0]->len = flag[0]->width;
}

void	ft_printfhex1(t_flags **flag, unsigned int hex, int len)
{
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus == 1)
		ft_smallhex(flag, len, (uintptr_t) hex);
	if (flag[0]->hastag && hex)
		flag[0]->len += 2;
}

void	ft_printfhex2(t_flags **flag, unsigned int hex, int len)
{
	if (flag[0]->width > len && flag[0]->width > flag[0]->precision
		&& flag[0]->minus != 1)
		ft_smallhex(flag, len, (uintptr_t) hex);
	if (flag[0]->hastag && hex)
		ft_hex0x(flag);
}
