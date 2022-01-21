/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:25:51 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:32:42 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	cont;

	cont = 0;
	if (!s)
		return ;
	while (s[cont])
	{
		write (fd, &s[cont], 1);
		cont++;
	}
	write(fd, "\n", 1);
}
