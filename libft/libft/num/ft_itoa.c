/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:00:50 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:32:05 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static int	ft_lenint(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		n = (-1) * n;
		cont++;
	}
	while (n > 9)
	{
		n = n / 10;
		cont++;
	}
	cont++;
	return (cont);
}

static char	*ft_putthenbr(long n)
{
	char	*str;
	int		len;
	int		cont;

	cont = ft_lenint(n);
	len = ft_lenint(n) - 1;
	str = (char *) malloc(ft_lenint(n) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = (-1) * n;
		str[0] = '-';
	}
	while (n > 9)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[len] = n + 48;
	str[cont] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	n = (long) n;
	str = ft_putthenbr(n);
	return (str);
}
