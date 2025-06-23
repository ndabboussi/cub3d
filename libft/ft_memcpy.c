/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:34:29 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 11:54:37 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == (void *)0 && dest == (void *)0)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char    *dest = "";
	char    *dest1 = "";
	char	*src = "";
	size_t  n = 3;
	printf("original= %s\n", dest);
//	ft_memcpy(dest, src, n);
	memcpy(dest1, src, n);
//	printf("ft_memcopy= %s\n", dest);
	printf("memcopy= %s\n", dest1);
	return (0);
}*/
