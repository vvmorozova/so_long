/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:44:11 by eward             #+#    #+#             */
/*   Updated: 2022/04/22 14:44:13 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf(msg);
	exit(0);
}

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	unsigned long	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if (src >= dst)
	{
		while ((i < len))
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
		}
	}
	else
	{
		while ((i < len--))
		{
			*((char *)(dst + len)) = *((char *)(src + len));
		}
	}
	return (dst);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	i = 0;
	while (*(str1 + i) && *(str2 + i) && i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*((unsigned char *)(s1 + i)) -
				*((unsigned char *)(s2 + i)));
		i++;
	}
	if (i == n)
		return (0);
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned long	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
	}
	return (dst);
}
