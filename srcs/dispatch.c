/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:09:28 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/23 16:43:48 by adrianda         ###   ########.fr       */
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
	dispatch['u'] = &handle_int;
	dispatch['p'] = &handle_ptr;
	dispatch['x'] = &handle_hex;
	dispatch['X'] = &handle_hex;
	if (dispatch[(unsigned char)format_char] == NULL)
		return (0);
	return (dispatch[(unsigned char)format_char](args));
}
