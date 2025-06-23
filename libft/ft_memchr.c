/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:32:49 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 12:07:06 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = (const char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	s[10] = "Vae Victis";
	int	c = 'i';
	size_t	n = 10;
	printf("original= %s\n", s);
	void *result = memchr(s, c, n);
	void *result2 = ft_memchr(s, c, n);
	printf("memchr= %p\n", result);
	printf("ft_memchr= %p\n", result2);
	printf("memchr= %p\n", memchr(s, c, n));
	printf("ft_memchr= %p\n", ft_memchr(s, c, n));
	return (0);
}*/
