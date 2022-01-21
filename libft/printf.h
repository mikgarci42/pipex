/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:58:49 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/28 17:58:52 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

typedef struct s_flags {
	int		zero;
	int		minus;
	int		isprecision;
	int		width;
	int		precision;
	int		minusprecision;
	int		hexb;
	int		len;
	int		unsin;
	long	num;
	int		wii;
	int		hastag;
	int		printnum;
	int		plus;
	int		space;
}				t_flags;

int		ft_printf(const char *str, ...);
void	ft_flag(int *i, const char *str, va_list ap);
int		ft_fillflags(t_flags **flag, int i, const char *str, va_list ap);
int		ft_character(t_flags **flag, const char *str, int i, va_list ap);
void	ft_initflag(t_flags **flag);
int		ft_search(char *str, char c);
void	ft_printfprint(int	*i, const char *str);
int		ft_fillflags1(const char *str, t_flags **flag, int i);
int		ft_filldest(t_flags **flag, int i, const char *str, char *dest);

//Para el d
int		ft_numlen(long int num, t_flags **flag);
void	ft_putspace(long int len, char c);
void	ft_printfnum(t_flags **flag, va_list ap);	
void	ft_printfnum2(t_flags **flag, long int num, long len);
void	ft_printfnum3(t_flags **flag, long int num, long len);
void	ft_putnumd(t_flags **flag, long int num);
void	ft_putnumd2(t_flags **flag, int cont, long int num, long len);
void	ft_small(t_flags	**flag, int len, int a);
void	ft_small2(t_flags **flag, int cont, int a, long len);

//Para el s
void	ft_printfstr(t_flags **flag, va_list ap);
void	ft_printfstr2(t_flags **flag, int len, char *str, int a);
void	ft_strwrite(char *str, int len);

// Para el c
void	ft_printchar(t_flags **flag, va_list ap);

// Para el p
void	ft_printpoint(t_flags **flag, va_list ap);
void	ft_printpoint2(t_flags **flag);
int		ft_printpoint3(t_flags **flag, int len, uintptr_t point);
int		ft_contpoint(uintptr_t ptr);
int		ft_puthex(uintptr_t a, char *str, int cont);
int		ft_writepoint(uintptr_t	point, char	*str);

//para el x
void	ft_printhexa(t_flags **flag, va_list ap);
void	ft_printfhex1(t_flags **flag, unsigned int hex, int len);
void	ft_printfhex2(t_flags **flag, unsigned int hex, int len);
void	ft_printhexa3(t_flags **flag, int len);
int		ft_conthex(unsigned int hex);
void	ft_writehex(t_flags **flag, char *str, int len, int a);
void	ft_smallhex(t_flags**flag, int len, uintptr_t hex);
void	ft_hex0x(t_flags **flag);

#endif
