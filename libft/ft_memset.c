/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:58:59 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/13 14:07:10 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
int	main()
{
	char	s[11] = "123456789";
	char    s1[11] = "123456789";
	int	c = 48;
	size_t	n = 12;
	printf("original = %s\n", s);
	ft_memset(s, c, n);
	printf("ft_memset= %s\n", s);
	printf("s1=%s\n", s1);
	memset(s1, c, n);
	printf("memset = %s\n", s1);
	return (0);
}*/
