/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:01:42 by eward             #+#    #+#             */
/*   Updated: 2022/01/11 21:01:44 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digs(int n)
{
	unsigned int	help;
	int				i;

	help = (unsigned int)(n);
	i = 1;
	if (n < 0)
	{
		i++;
		help = (unsigned int)(-n);
	}
	while (help > 9)
	{
		i++;
		help = help / 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	help;
	char			rez[20];
	int				i;

	help = (unsigned int)(n);
	i = count_digs(n);
	rez[0] = 0;
	if (n < 0)
	{
		rez[0] = '-';
		help = (unsigned int)(-n);
	}
	rez[i] = '\0';
	i--;
	while (i >= 0 && rez[i] != '-')
	{
		rez[i--] = help % 10 + '0';
		help = help / 10;
	}
	write(1, rez, ft_strlen(rez));
	return (ft_strlen(rez));
}

int	count_uns_digs(unsigned int n)
{
	unsigned int	help;
	int				i;

	help = (unsigned int)(n);
	i = 1;
	while (help > 9)
	{
		i++;
		help = help / 10;
	}
	return (i);
}

int	ft_put_uns_nbr(unsigned int n)
{
	unsigned int	help;
	char			rez[50];
	int				i;

	help = (unsigned int)(n);
	i = count_uns_digs(n);
	rez[i] = '\0';
	i--;
	while (i >= 0 && rez[i] != '-')
	{
		rez[i--] = help % 10 + '0';
		help = help / 10;
	}
	write(1, rez, ft_strlen(rez));
	return (ft_strlen(rez));
}

int	ft_putint(int n)
{
	unsigned int	help;
	char			rez[50];
	int				i;

	i = count_digs(n);
	help = (unsigned int)(n);
	if (n < 0)
	{
		rez[0] = '-';
		help = (unsigned int)(-n);
	}
	rez[i] = '\0';
	i--;
	while (i >= 0 && rez[i] != '-')
	{
		rez[i--] = help % 10 + '0';
		help = help / 10;
	}
	write(1, rez, ft_strlen(rez));
	return (ft_strlen(rez));
}
