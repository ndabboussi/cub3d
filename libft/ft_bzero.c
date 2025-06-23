/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:09:16 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/13 14:33:47 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	char	s[20] = "ilnyapasdezero";
	char	s1[20] = "ilnyapasdezero";
	size_t	n = 5;
	printf("%s\n", s);
	ft_bzero(s, n);
	bzero(s1, n);
	printf("bzero= %s\n", s);
	printf("bzero= %s\n", s1);
	return (0);
}*/
