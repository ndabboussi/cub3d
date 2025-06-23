/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:25:15 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/27 10:39:27 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (ptr1[i] == ptr2[i] && (i + 1) < n)
		i++;
	return (ptr1[i] - ptr2[i]);
}

/*int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "hello";
	char	str3[] = "world";

	printf("Comparaison de str1 et str2 : %d\n", memcmp(str1, str2, 5));
	// Devrait afficher 0 (identiques)
	printf("Comparaison de str1 et str3 : %d\n", memcmp(str1, str3, 5));
	// Devrait afficher une valeur différente de 0
	return (0);
}*/