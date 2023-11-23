/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benny <benny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:10:36 by benny             #+#    #+#             */
/*   Updated: 2023/11/21 01:48:54 by benny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	contains(char f, char *o)
{
	while (*o)
	{
		if (f == *o)
			return (1);
		o++;
	}
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *s)
{
	if (s == NULL)
		ft_putstr_fd("(null)", 1);
	else
		ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	formater(char *f, va_list d)
{
	char	*options;

	options = "cspdiuxX%";
	if (!contains(*f, options))
		return (0);
	f++;
	if (*f == 'c')
		ft_putchar(va_arg(d, int));
	else if (*f == 's' )
		return (put_str(va_arg(d, char *)));
	else if (*f == 'p')
		return (put_pointer_addr(va_arg(d, void *)));
	else if (*f == 'd' || *f == 'i')
		return (putnbr_base(va_arg(d, int), "0123456789"));
	else if (*f == 'u')
		return (putnbr_base(va_arg(d, unsigned int), "0123456789"));
	else if (*f == 'x')
		return (putnbr_base(va_arg(d, unsigned int), "0123456789abcdef"));
	else if (*f == 'X')
		return (putnbr_base(va_arg(d, unsigned int), "0123456789ABCDEF"));
	else if (*f == '%')
		ft_putchar('%');
	return (1);
}


int	ft_printf(const char *format, ...)
{
	char	*f;
	int		i;
	va_list	data;

	if (!format)
		return (-1);
	va_start(data, format);
	f = (char *)format;
	i = 0;
	while (*f)
	{
		if (*f == '%')
		{
			i += formater(f, data);
			f += 2;
		}
		else
		{
			ft_putchar_fd(*f, 1);
			f++;
			i++;
		}
	}
	va_end(data);
	return (i);
}
