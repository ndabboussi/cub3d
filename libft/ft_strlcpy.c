/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:58:49 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/20 17:02:27 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (siz == 0)
		return (len);
	while (i + 1 < siz && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*#include <stdio.h>
int	main()
{
	char dst[5] = "oui";
	const char *src;

	src = "Hello World";
	printf("%zu\n", ft_strlcpy(dst, src, 0));
	printf("%s\n", dst);
	return (0);
}*/
