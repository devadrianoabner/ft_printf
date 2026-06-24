/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:09:28 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 12:57:04 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	dispatch_convertions(char format_char, va_list args)
{
	t_handler	dispatch[256];

	ft_bzero(dispatch, sizeof(dispatch));
	dispatch['%'] = &handle_percent;
	dispatch['c'] = &handle_char;
	dispatch['s'] = &handle_str;
	dispatch['d'] = &handle_int;
	dispatch['i'] = &handle_int;
	dispatch['u'] = &handle_int_unsigned;
	dispatch['p'] = &handle_ptr;
	dispatch['x'] = &handle_hex_lower;
	dispatch['X'] = &handle_hex_upper;
	if (dispatch[(unsigned char)format_char] == NULL)
		return (0);
	return (dispatch[(unsigned char)format_char](args));
}
