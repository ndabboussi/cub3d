/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:35:49 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 11:39:00 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (siz <= 0 || lendst >= siz)
		lendst = siz;
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i + 1 < siz)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lensrc + lendst);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	size_t res;
	char dst[10] = "oui";
	const char *src;

	src = "123456789";
	res = strlcat(dst, src, 10);
	printf("%zu\n", res);
	printf("%zu\n", ft_strlcat(dst, src, 10));
	return (0);
}*/
