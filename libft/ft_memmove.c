/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:39:21 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/20 13:14:19 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dest_cpy;

	i = 0;
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (dest_cpy > src_cpy)
	{
		while (n > 0)
		{
			n--;
			dest_cpy[n] = src_cpy[n];
		}
		return (dest);
	}
	while (i < n)
	{
		(dest_cpy[i] = src_cpy[i]);
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int     main()
{
	//char    dest[15] = "blablablablabla";
	char    dest1[7] = "blabla";
//	char    src[20] = "01234567890123456789";
	char    src2[20] = "jenaipascomprislepro";
	printf("original= %s\n", dest1);
	memmove(dest1, src2, 15);
	ft_memmove(dest1, src2, 9);
	printf("memmove= %s\n", dest1);
	printf("ft_memmove= %s\n", dest1);
	return (0);
}*/