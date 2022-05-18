/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:58:37 by eward             #+#    #+#             */
/*   Updated: 2022/05/06 15:58:38 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	digits(int n)
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

char	*ft_itoa(int n)
{
	unsigned int	help;
	char			*rez;
	int				i;

	help = (unsigned int)(n);
	i = digits(n);
	rez = (char *)malloc(sizeof(char) * (i + 1));
	if (rez == 0)
		return (0);
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
		rez[i] = help % 10 + '0';
		i--;
		help = help / 10;
	}
	return (rez);
}
