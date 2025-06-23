/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:49 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 12:03:55 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] != '\0' && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
int	main()
{
	const char *s1 = "Destination";
	const char *s2 = "Destin";
	size_t n = 3;
	const char *s3 = "Destin";
	const char *s4 = "Destroyeur";
	size_t m= 8;
	printf("scenario 1= %d\n", ft_strncmp(s1, s2, n));
	printd("scenario 2 = %d\n", ft_strncmp(s3, s4, m));
	return (0);
}*/
