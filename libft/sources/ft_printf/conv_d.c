/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:34:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/05 19:57:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	itoa_size(int n)
{
	size_t	size;

	size = n <= 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	d_copy(va_list ap, char *buffer)
{
	int		d;
	size_t	size;

	d = va_arg(ap, int);
	size = itoa_size(d);
	if (!d)
	{
		*buffer = '0';
		return ;
	}
	if (d < 0)
		buffer[0] = '-';
	while (d)
	{
		buffer[--size] = ft_abs(d % 10) + '0';
		d /= 10;
	}
}

size_t	d_size(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	return (itoa_size(d));
}
