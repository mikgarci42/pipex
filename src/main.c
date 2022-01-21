/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:18:12 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/21 17:54:16 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_execommand(t_data info, int pos)
{
	int		cont;
	char	**dest;
	int		j;

	dest = ft_putcommand(info.argv, 2 + pos);
	cont = 0;
	j = 0;
	while (j < info.argc - 2)
	{
		if (j != pos)
			close(info.pipes[j][0]);
		if (pos + 1 != j)
			close(info.pipes[j][1]);
		j++;
	}
	dup2(info.pipes[pos][0], 0);
	close(info.pipes[pos][0]);
	dup2(info.pipes[pos + 1][1], 1);
	close(info.pipes[pos + 1][1]);
	while (info.list[cont])
	{
		if (!access(ft_strjoin(info.list[cont], dest[0]), X_OK))
			execve(ft_strjoin(info.list[cont], dest[0]), dest, info.envp);
		cont++;
	}
}

void	ft_startfork(int argc, t_data info)
{
	int	cont;

	cont = 0;
	while (cont < argc - 3)
	{
		info.pids[cont] = fork();
		if (info.pids[cont] == 0)
		{
			ft_execommand(info, cont);
		}
		cont++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	info;

	if (argc > 4)
	{
		ft_splitenve(envp, &info);
		if (!info.list)
			return (0);
		ft_complenve(&info);
		ft_setpipe(argc - 3, &info);
		if (!info.pipes)
			return (ft_freelist(&info));
		info.pids = malloc((argc - 3) * sizeof(int));
		if (!info.pids)
			return (2);
		if (!ft_openfile(argv, &info, argc))
			return (3);
		info.argv = argv;
		info.envp = envp;
		info.argc = argc;
		ft_startfork(argc, info);
		ft_freelist(&info);
		free(info.pids);
		ft_freepipes(&info, argc - 2);
	}
}
