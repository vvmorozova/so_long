/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:50:31 by eward             #+#    #+#             */
/*   Updated: 2022/01/13 13:51:16 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_point_hex(unsigned long n)
{
	unsigned long	i;
	char			*basis;
	char			rez[20];
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

int	ft_typable(char c)
{
	char	*convs;

	convs = "cspdiuxX%\0";
	while (*(convs))
	{
		if (*(convs) == c)
			return (1);
		convs++;
	}
	return (0);
}

int	ft_print_to_cmd(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putpointer(va_arg(*args, unsigned long)));
	if (c == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_put_uns_nbr(((unsigned int)va_arg(*args, int))));
	if (c == 'x')
		return (ft_puthex((unsigned int)va_arg(*args, unsigned int)));
	if (c == 'X')
		return (ft_put_big_hex((unsigned int)va_arg(*args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_putpointer(unsigned long p)
{
	ft_putstr("0x");
	return (2 + ft_put_point_hex(p));
}
