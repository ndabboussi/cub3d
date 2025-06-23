/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:56:25 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:39:00 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (const unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char str[] = "test pour voir";
	
	ft_memset(str, '*', 3);
	printf("%s", str);
}
*/