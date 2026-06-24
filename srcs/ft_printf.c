/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:23:32 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 16:49:41 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		num_bytes;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	num_bytes = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			num_bytes += dispatch_convertions(format[i], args);
		}
		else
		num_bytes = num_bytes + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (num_bytes);
}
