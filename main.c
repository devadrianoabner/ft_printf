/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:24:19 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/23 19:48:59 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	returns;
	
	/// TEST % ///
	returns = ft_printf("Hello Wrold 100%%\n");
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold 100%%\n");
	printf("Valor retornado do printf: %i\n\n", returns);


	/// TEST C ///
	returns = ft_printf("Hello Wrold %c\n", 'H');
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %c\n", 'H');
	printf("Valor retornado do printf: %i\n\n", returns);

		/// TEST D ///
	returns = ft_printf("Hello Wrold %d\n", 100);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %d\n", 100);
	printf("Valor retornado do printf: %i\n\n", returns);
	
	/// TEST x ///
	returns = ft_printf("Hello Wrold %x\n", 160);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %x\n", 160);
	printf("Valor retornado do printf: %i\n\n", returns);
	return (0);
}
// cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf