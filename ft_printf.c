/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:55:19 by zlazrak           #+#    #+#             */
/*   Updated: 2022/11/04 11:39:55 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_call(va_list ap, char c, int *l)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(ap, int), l);
	else if (c == 'u')
		ft_putun(va_arg(ap, unsigned int), l);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), l);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(ap, unsigned int), l, c);
	else if (c == 'c')
		ft_putchar(va_arg(ap, int), l);
	else if (c == 'p')
		ft_putaddr(va_arg(ap, size_t), l, 0);
	else if (c == '%')
		ft_putchar(c, l);
	else
		ft_putchar(c, l);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;	
	int		l;
	size_t	i;

	va_start(ap, s);
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			ft_call(ap, s[++i], &l);
			if (l < 0)
				return (-1);
			i++;
			continue ;
		}
		if (s[i] != '%')
			ft_putchar(s[i], &l);
		if (l < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (l);
}
