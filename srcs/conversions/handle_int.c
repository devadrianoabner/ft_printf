/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:27:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 13:20:24 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	putnbr_and_count(long long nbr)
{
	char	c;
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += putnbr_and_count(nbr / 10);
	c = (nbr % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

static int	put_u_nbr_and_count(unsigned long long nbr)
{
	char	c;
	int		count;

	count = 0;
	if (nbr >= 10)
		count += put_u_nbr_and_count(nbr / 10);
	c = (nbr % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	handle_int(va_list args)
{
	long long	nbr;

	nbr = va_arg(args, int);
	return (putnbr_and_count(nbr));
}

int	handle_int_unsigned(va_list args)
{
	unsigned long long	nbr;

	nbr = va_arg(args, unsigned int);
	return (put_u_nbr_and_count(nbr));
}
