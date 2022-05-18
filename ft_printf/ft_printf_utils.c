/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:58:20 by eward             #+#    #+#             */
/*   Updated: 2022/01/11 20:58:22 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../includes/so_long.h"

unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	char	*err;

	err = "(null)";
	if (!s)
	{
		ft_putstr(err);
		return (6);
	}
	write(1, s, (int)ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_puthex(unsigned int n)
{
	unsigned int	i;
	char			*basis;
	char			rez[10];
	int				len;

	len = 1;
	basis = "0123456789abcdef\0";
	*(rez) = '0';
	*(rez + 1) = '\0';
	i = n;
	while (n / 16 > 0)
	{
		len++;
		n = n / 16;
	}
	n = i;
	*(rez + len) = '\0';
	i = 0;
	while (n > 0)
	{
		*(rez + len - ++i) = *(basis + n % 16);
		n = n / 16;
	}
	ft_putstr(rez);
	return (len);
}

int	ft_put_big_hex(unsigned int n)
{
	unsigned int	i;
	char			*basis;
	char			rez[10];
	int				len;

	len = 1;
	basis = "0123456789ABCDEF\0";
	*(rez) = '0';
	*(rez + 1) = '\0';
	i = n;
	while (n / 16 > 0)
	{
		len++;
		n = n / 16;
	}
	n = i;
	i = 0;
	*(rez + len) = '\0';
	while (n > 0)
	{
		*(rez + len - ++i) = *(basis + n % 16);
		n = n / 16;
	}
	ft_putstr(rez);
	return (len);
}
