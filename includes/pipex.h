/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:35:25 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/23 11:26:39 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../printf/printf.h"

typedef struct s_data {
	int		*pids;
	int		**pipes;
	char	**list;
	char	**argv;
	char	**envp;
	int		argc;
	int		fd1;
	int		fd2;
}	t_data;

void	ft_splitenve(char **envp, t_data *info);
void	ft_complenve(t_data *info);
int		ft_openfile(char **argv, t_data *info, int argc);
char	**ft_putcommand(char **argv, int pos);
void	ft_setpipe(int cont, t_data *info);
void	ft_execommand(t_data info, int pos);
void	ft_startfork(int argc, t_data info);
int		ft_freelist(t_data *info);
int		ft_freepipes(t_data *info, int a);

#endif
