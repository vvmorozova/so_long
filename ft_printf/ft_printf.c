/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eward <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:54 by eward             #+#    #+#             */
/*   Updated: 2022/01/10 15:18:57 by eward            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help(const char **fmt, int *was_percent, int *typed)
{
	if (**fmt == '%' && *typed == 0)
		*was_percent = 1;
	else
	{
		*was_percent = 0;
		*typed = 0;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		was_percent;
	int		len;
	int		typed;

	len = 0;
	was_percent = 0;
	typed = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (was_percent == 1 && ft_typable(*fmt))
		{
			len = len + ft_print_to_cmd(&args, *fmt);
			typed = 1;
		}
		else if (*fmt != '%')
			len = len + ft_putchar(*fmt);
		help(&fmt, &was_percent, &typed);
		fmt++;
	}
	va_end(args);
	return (len);
}
