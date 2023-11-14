/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benny <benny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:10:36 by benny             #+#    #+#             */
/*   Updated: 2023/11/07 21:02:47 by benny            ###   ########.fr       */
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
	int		j;
	float	decnbr;
	char	decstr[20];

	va_start (args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			i += 2;
		}
		if (format[i] == '%' && format[i + 1] == 's')
		{
			slen = ft_strlen(va_arg(args, char *));
			s = malloc(slen * sizeof(char));
			s = va_arg(args, char *);
			while (s[j])
			{
				write(1, &s[j], 1);
				i++;
			}
			free(s);
			i += 2;
		}
		if (format[i] == '%' && format[i + 1] == 'p')
		{
			ptr = va_arg(args, void *);
			add = (unsigned long long int)ptr;
			j = 0;
			while (add >= 0)
			{
				ptrdigit = add % 16;
				if (ptrdigit < 10)
					buffer[j++] = '0' + ptrdigit;
				else
					buffer[j++] = 'a' + (ptrdigit - 10);
				add /= 16;
			}
			while (j > 0)
			{
				write(1, &buffer[j], 1);
			}
			i += 2;
		}
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			decnbr = va_arg(args, float);
			if (decnbr < 0)
			{
				write(1, "-", 1);
				decnbr *= -1;
			}
			while ((long)decnbr > 0)
			{
				decstr[j] = (decnbr % 10) + '0';
				decnbr /= 10;
			}
		}
		i++;
	}
}

int main(void)
{
	char *s = "ola";
	printf("%p", s);
	ft_printf("%p", s);
}