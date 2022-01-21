/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:25:58 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:56:19 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_initflag(t_flags **flag)
{
	flag[0]->zero = -1;
	flag[0]->minus = -1;
	flag[0]->isprecision = -1;
	flag[0]->width = -1;
	flag[0]->precision = -1;
	flag[0]->minusprecision = 0;
	flag[0]->hexb = 0;
	flag[0]->unsin = 0;
	flag[0]->len = 0;
	flag[0]->num = 0;
	flag[0]->wii = 0;
	flag[0]->hastag = 0;
	flag[0]->printnum = 1;
	flag[0]->plus = 0;
	flag[0]->space = 0;
}

void	ft_flag(int *i, const char *str, va_list ap)
{
	t_flags	*flag;

	flag = malloc(sizeof(t_flags) * 2);
	ft_initflag(&flag);
	i[0] = ft_fillflags(&flag, i[0], str, ap);
	if (flag[0].len > flag[0].width)
		i[1] = i[1] + flag[0].len;
	else
		i[1] = i[1] + flag[0].width + flag[0].wii;
	free(flag);
	return ;
}

int	ft_fillflags1(const char *str, t_flags **flag, int i)
{
	while (ft_search("+-0# ", str[i]))
	{
		if (str[i] == '#')
			flag[0]->hastag = 1;
		else if (str[i] == '0')
			flag[0]->zero = 1;
		else if (str[i] == '-')
			flag[0]->minus = 1;
		else if (str[i] == '+')
			flag[0]->plus = 1;
		else if (str[i] == ' ')
			flag[0]->space = 1;
		i++;
	}
	return (i);
}

int	ft_filldest(t_flags **flag, int i, const char *str, char *dest)
{
	int	a;

	a = 0;
	if (str[i] <= '9' && str[i] >= '0')
	{
		while (str[i] <= '9' && str[i] >= '0')
		{
			dest[a] = str[i];
			a++;
			i++;
		}
		dest[a] = 0;
		flag[0]->width = ft_atoi(dest);
	}
	return (i);
}

int	ft_fillflags(t_flags **flag, int i, const char *str, va_list ap)
{
	int		a;
	char	*dest;

	i++;
	i = ft_fillflags1(str, flag, i);
	dest = (char *) malloc(sizeof(char) * 11);
	i = ft_filldest(flag, i, str, dest);
	if (str[i] == '.')
	{
		i++;
		flag[0]->isprecision = 1;
		if (str[i] <= '9' && str[i] >= '0')
		{
			a = 0;
			while (str[i] <= '9' && str[i] >= '0')
				dest[a++] = str[i++];
			dest[a] = '\0';
			flag[0]->precision = ft_atoi(dest);
		}
	}
	i = ft_character(flag, str, i, ap);
	free(dest);
	return (i);
}
