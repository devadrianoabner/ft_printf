/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:18:58 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 11:50:12 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	puthex_and_count(unsigned int nbr, char *base)
{
	int		count;

	count = 0;
	if (nbr >= 16)
		count += puthex_and_count(nbr / 16, base);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}

int	handle_hex_lower(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (puthex_and_count(nbr, "0123456789abcdef"));
}

int	handle_hex_upper(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (puthex_and_count(nbr, "0123456789ABCDEF"));
}
