/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:41:07 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 15:31:14 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*copy;

	i = 0;
	len_s = (size_t)ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s - (size_t)start < len)
		len = len_s - (size_t)start;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = ((char *)s)[start];
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}

/*#include <stdio.h>
int	main()
{
	char const s[15] = "012345678901234";
	unsigned int start = 5;
	size_t len = 3;
	printf("%s originale\n", s);
	printf("%s ft_substr\n", ft_substr(s, start, len));
	return (0);
}*/
