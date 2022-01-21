/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:48:11 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 15:57:10 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h" 
#include "../printf.h" 
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		i[2];
	va_list	ap;

	va_start(ap, str);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		if (str[i[0]] == '%')
		{
			if (str[i[0] + 1] == '%')
			{
				i[0] += 2;
				write(1, "%", 1);
				i[1] += 1;
			}
			else
				ft_flag(i, str, ap);
		}
		else
			ft_printfprint(i, str);
	}
	va_end(ap);
	return (i[1]);
}

void	ft_printfprint(int	*i, const char *str)
{
	write(1, &str[i[0]], 1);
	i[0]++;
	i[1]++;
}

int	ft_character(t_flags **flag, const char *str, int i, va_list ap)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_printfnum(flag, ap);
	else if (str[i] == 'u')
	{
		flag[0]->unsin = 1;
		ft_printfnum(flag, ap);
	}
	else if (str[i] == 's')
		ft_printfstr(flag, ap);
	else if (str[i] == 'c')
		ft_printchar(flag, ap);
	else if (str[i] == 'p')
		ft_printpoint(flag, ap);
	else if (str[i] == 'x')
		ft_printhexa(flag, ap);
	else if (str[i] == 'X')
	{
		flag[0]->hexb = 1;
		ft_printhexa(flag, ap);
	}
	else
		i--;
	return (i + 1);
}
