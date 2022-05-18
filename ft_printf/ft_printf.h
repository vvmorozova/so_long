/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:19:01 by eward             #+#    #+#             */
/*   Updated: 2022/01/10 15:19:02 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../includes/so_long.h"

unsigned long	ft_strlen(char *s);
int				ft_putstr(char *s);
int				ft_printf(const char *fmt, ...);
int				ft_putchar(char c);
int				ft_puthex(unsigned int n);
int				ft_put_big_hex(unsigned int n);
int				ft_putnbr(int n);
int				ft_put_uns_nbr(unsigned int n);
int				ft_putint(int n);
int				ft_putpointer(unsigned long p);
int				ft_puthex(unsigned int n);
int				ft_print_to_cmd(va_list *args, char c);
int				ft_typable(char c);
int				ft_put_point_hex(unsigned long n);
#endif
