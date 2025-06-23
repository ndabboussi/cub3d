/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:02:07 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 15:47:30 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i + 1 < n)
		i++;
	return (str1[i] - str2[i]);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
        const char *s1 = "Destination";
        const char *s2 = "Destinag";
        size_t n = 8;
        const char *s3 = "Destin";
        const char *s4 = "Destroyeur";
        size_t m= 8;
	printf("scenario 1 memcmp= %d\n", memcmp(s1, s2, n));
        printf("scenario 1 ft= %d\n", ft_memcmp(s1, s2, n));
	printf("scenario 2 memcmp= %d\n", memcmp(s3, s4, m));
        printf("scenario 2 ft= %d\n", ft_memcmp(s3, s4, m));
        return (0);
}*/
