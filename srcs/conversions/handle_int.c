/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:27:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 11:49:30 by adrianda         ###   ########.fr       */
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

int	handle_int(va_list args)
{
	long long	nbr;

	nbr = va_arg(args, int);
	return (putnbr_and_count(nbr));
}
