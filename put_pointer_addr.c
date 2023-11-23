/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benny <benny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:12:12 by benny             #+#    #+#             */
/*   Updated: 2023/11/20 17:06:44 by benny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer_addr(void *p)
{
	long long int	add;
	int				i;
	int				ptrdigit;
	char			buffer[20];
	int				l;

	add = (unsigned long long int)p;
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
	l = i;
	while (i > 0)
	{
		write(1, &buffer[i], 1);
		i++;
	}
	return (l);
}
