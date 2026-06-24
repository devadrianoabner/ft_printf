/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:24:19 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/24 13:23:05 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	returns;
	
	// 	%, c, s, d, i, u, p, x, X 
	
	/// TEST % ///
	ft_printf(" /// TEST %%\n\n///");
	returns = ft_printf("Hello Wrold 100%%\n");
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold 100%%\n");
	ft_printf("Valor retornado do printf: %i\n\n", returns);
	
	/// TEST c ///
	ft_printf(" /// TEST c\n\n///");
	returns = ft_printf("Hello Wrold %c\n", 'H');
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %c\n", 'H');
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST s ///
	ft_printf(" /// TEST s\n\n///");
	returns = ft_printf("Hello Wrold %s\n", "Hello World");
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %s\n", "Hello World");
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST d ///
	ft_printf(" /// TEST d\n\n///");
	returns = ft_printf("Hello Wrold %d\n", 100);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %d\n", 100);
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST i ///
	ft_printf(" /// TEST i\n\n///");
	returns = ft_printf("Hello Wrold %i\n", 0100);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %i\n", 0100);
	ft_printf("Valor retornado do printf: %i\n\n", returns);
	
	/// TEST u ///
	ft_printf(" /// TEST u\n\n///");
	returns = ft_printf("Hello Wrold %u\n", -100);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %u\n", -100);
	ft_printf("Valor retornado do printf: %i\n\n", returns);
	
	/// TEST p ///
	ft_printf(" /// TEST p\n\n///");
	returns = ft_printf("Hello Wrold %p\n", &returns);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %p\n", &returns);
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST x ///
	ft_printf(" /// TEST x\n\n///");
	returns = ft_printf("Hello Wrold %x\n", -27389173);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %x\n", -27389173);
	ft_printf("Valor retornado do printf: %i\n\n", returns);

	/// TEST X ///
	ft_printf(" /// TEST X\n\n///");
	returns = ft_printf("Hello Wrold %X\n", -27389173);
	printf("Valor retornado do ft_printf: %i\n", returns);
	returns = printf("Hello Wrold %X\n", -27389173);
	ft_printf("Valor retornado do printf: %i\n\n", returns);
		return (0);
}
// cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf