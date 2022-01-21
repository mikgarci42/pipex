/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:54:20 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/21 17:53:24 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_openfile(char **argv, t_data *info, int argc)
{
	int	cont;

	info->fd1 = open(argv[1], O_RDONLY);
	if (info->fd1 < 0)
		return (0);
	cont = 0;
	while (argv[cont])
		cont++;
	info->fd2 = open(argv[cont - 1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (info->fd2 < 0)
		return (0);
	close(info->pipes[0][0]);
	info->pipes[0][0] = info->fd1;
	close(info->pipes[argc - 3][1]);
	info->pipes[argc - 3][1] = info->fd2;
	return (1);
}

char	**ft_putcommand(char **argv, int pos)
{
	char	**dest;

	dest = ft_split(argv[pos], ' ');
	if (!dest)
		return (NULL);
	return (dest);
}

void	ft_setpipe(int cont, t_data *info)
{
	int	len;

	info->pipes = malloc((cont + 1) * sizeof(int *));
	if (!info->pipes)
		return ;
	len = 0;
	while (len <= cont)
	{
		info->pipes[len] = malloc(2 * sizeof(int));
		if (!info->pipes[len])
		{
			while (--len >= 0)
				free(info->pipes[len]);
			free(info->pipes);
			return ;
		}
		pipe(info->pipes[len]);
		len++;
	}
}
