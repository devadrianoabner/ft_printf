/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:24:19 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 12:52:15 by adrianda         ###   ########.fr       */
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
	ft_printf("Valor retornado do printf: %i\n\n", returns);


	/// TEST c ///
	returns = ft_printf("Hello Wrold %c\n", 'H');
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %c\n", 'H');
	ft_printf("Valor retornado do printf: %i\n\n", returns);

		/// TEST d ///
	returns = ft_printf("Hello Wrold %d\n", 100);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %d\n", 100);
	ft_printf("Valor retornado do printf: %i\n\n", returns);
	
	/// TEST x ///
	returns = ft_printf("Hello Wrold %x\n", -27389173);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %x\n", -27389173);
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST p ///
	returns = ft_printf("Hello Wrold %p\n", &returns);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %p\n", &returns);
	ft_printf("Valor retornado do printf: %i\n\n", returns);
	return (0);
}
// cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf