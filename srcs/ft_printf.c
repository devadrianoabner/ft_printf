/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:23:32 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/23 16:20:28 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		num_bytes;
	int		i;

	i = 0;
	num_bytes = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			num_bytes += dispatch_convertions(format[i], args);
		}
		else
		num_bytes = num_bytes + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (num_bytes);
}
