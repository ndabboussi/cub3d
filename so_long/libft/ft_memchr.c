/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:46 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:43:40 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ptr;

	ptr = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (const char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("Résultat : %p\n", ft_memchr("bonsoir", 's', 5));
	return (0);
}
*/