/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:27:36 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 12:49:26 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	putptr_and_count(unsigned long long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putptr_and_count(nbr / 16, base);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}

int	handle_ptr(va_list args)
{
	void				*ptr;
	unsigned long long	ptr_nbr;
	int					total_count;

	ptr = va_arg(args, void *);
	ptr_nbr = (unsigned long long) ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	total_count = write(1, "0x", 2);
	total_count += putptr_and_count(ptr_nbr, "0123456789abcdef");
	return (total_count);
}
