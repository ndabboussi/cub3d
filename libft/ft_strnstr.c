/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:35:37 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 14:35:32 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_big;
	char	*result;

	i = 0;
	j = 0;
	len_big = (size_t)ft_strlen(big);
	result = (char *)big;
	if (!*little)
		return (result);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len && i + j < len_big)
		{
			j++;
		}
		if (little[j] == '\0')
			return (&result[i]);
		j = 0;
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main()
{
	const char *big = "Un petit pas, deux petits pas, trois petits pas";
	const char *little = "petition";
	printf("ft_strnstr= %s\n", ft_strnstr(big, little, 4));
	//printf("strnstr= %d\n", strnstr(big, little, 8));
	return (0);
}*/
