/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contfun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:36:22 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:08 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int	ft_contpoint(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr >= 16)
	{
		ptr /= 16;
		len++;
	}
	return (len + 3);
}

int	ft_puthex(uintptr_t a, char *str, int cont)
{
	a = a + 48;
	if (a >= '0' && a <= '9')
	{
		str[cont] = a;
		cont++;
	}
	else
	{
		a = 39 + a;
		str[cont] = a;
		cont++;
	}
	return (cont);
}

int	ft_writepoint(uintptr_t	point, char	*str)
{
	uintptr_t	a;
	int			cont;

	a = 0;
	cont = 0;
	while (point >= 16)
	{
		a = point % 16;
		cont = ft_puthex(a, str, cont);
		point /= 16;
	}
	point = point + 48;
	if (point >= '0' && point <= '9')
	{
		str[cont] = point;
		cont++;
	}
	else
	{
		point = 39 + point;
		str[cont] = point;
		cont++;
	}
	str[cont] = 0;
	return (cont);
}

int	ft_search(char *str, char c)
{
	int	cont;

	cont = 0;
	while (str[cont])
	{
		if (str[cont] == c)
			return (1);
		cont++;
	}
	return (0);
}
