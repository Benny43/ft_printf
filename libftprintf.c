/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benny <benny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:10:36 by benny             #+#    #+#             */
/*   Updated: 2023/10/30 01:56:10 by benny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	c;
	char	*s;
	void	*ptr;
	int		slen;
	int		i;
	unsigned long long int add;
	char	buffer[20];
	int		ptrdigit;

	va_start (args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			format += 2;
		}
		if (*format == '%' && *(format + 1) == 's')
		{
			slen = ft_strlen(va_arg(args, char *));
			s = malloc(slen * sizeof(char));
			s = va_arg(args, char *);
			while (s[i])
			{
				write(1, &s[i], 1);
				i++;
			}
			free(s);
			format += 2;
		}
		if (*format == '%' && *(format + 1) == 'p')
		{
			ptr = va_arg(args, void *);
			add = (unsigned long long int)ptr;
			i = 0;
			while (add >= 0)
			{
				ptrdigit = add % 16;
				if (ptrdigit < 10)
					buffer[i++] = '0' + ptrdigit;
				else
					buffer[i++] = 'a' + (ptrdigit - 10);
				add /= 16;
			}
			while (i > 0)
			{
				write(1, &buffer[i], 1);
			}
			format += 2;
		}
		*format++;
	}
}

int main(void)
{
	char *s = "ola";
	printf("%p", s);
	ft_printf("%p", s);
}