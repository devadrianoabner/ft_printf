/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:23:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 12:56:50 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef int	(*t_handler)(va_list);
int	ft_printf(const char *format, ...);
int	dispatch_convertions(char format_char, va_list args);
int	handle_char(va_list args);
int	handle_str(va_list args);
int	handle_int(va_list args);
int	handle_hex_lower(va_list args);
int	handle_hex_upper(va_list args);
int	handle_percent(va_list args);
int	handle_ptr(va_list args);
int	handle_int_unsigned(va_list args);
#endif