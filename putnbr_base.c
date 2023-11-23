/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benny <benny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:12:10 by benny             #+#    #+#             */
/*   Updated: 2023/11/23 05:04:40 by benny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int_len(long n, char *base)
{
	int	baselen;
	int	len;

	baselen = 0;
	while (base[baselen])
		baselen++;
	len = 0;
	while (n != 0)
	{
		n /= baselen;
		len++;
	}
	return (len);
}

int	str_write(long long nb, char *str, char *base, int base_len)
{
	int	i;
	int	count;

	i = 0;
	while (nb != 0)
	{
		str[i] = base[nb % base_len];
		nb /= base_len;
		i++;
	}
	count = i;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (count);
}

int	putnbr_base(long n, char *base)
{
	char		*str;
	long long	nb;
	int			num_len;
	int			base_len;

	nb = n;
	if (nb == 0)
	{
		write(1, &"0", 1);
		return (1);
	}
	base_len = 0;
	if (nb < 0)
	{
		write(1, &"-", 1);
		nb = -nb;
	}
	while (base[base_len])
		base_len++;
	num_len = get_int_len(n, base);
	str = ft_calloc(num_len, sizeof(char));
	num_len += str_write(n, str, base, base_len);
	free(str);
	return (num_len + (n < 0));
}
