/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:48:54 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/15 21:23:17 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	ptr_s = (char *) s;
	i = ft_strlen(ptr_s);
	while (i >= 0)
	{
		if (ptr_s[i] == (char)c)
			return (&ptr_s[i]);
		i--;
	}
	return (NULL);
}
