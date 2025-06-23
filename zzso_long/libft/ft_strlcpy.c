/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:26:08 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:37:52 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*
int	main(void)
{
	char source[] = "Bon@ jou$$r";
	char dest[]= "df";
	char source2[] = "Bon@ jou$$r";
	char dest2[]= "df";

	ft_strlcpy(dest, source, 4);
	printf("dest : %s, src: %s\n", dest, source);
	strlcpy(dest2, source2, 4);
	printf("dest : %s, src: %s\n", dest2, source2);
	return 0;
}*/