/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:17:16 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/27 15:25:56 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start >= i)
	{
		return (ft_calloc(1, 1));
	}
	if (len > i - start)
		len = i - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	char	*str;
	char	*result;

	str = "Hello, world!";
	// Test case 1: Normal substring extraction
	result = ft_substr(str, 7, 5);
	printf("Test 1 - Expected 'world': %s\n", result);
	free(result);

	// Test case 2: Start index out of bounds (should return an empty string)
	result = ft_substr(str, 20, 5);
	printf("Test 2 - Expected '': %s\n", result);
	free(result);

	// Test case 3: Length greater than remaining string length
	result = ft_substr(str, 7, 50);
	printf("Test 3 - Expected 'world!': %s\n", result);
	free(result);

	// Test case 4: Extract from the beginning
	result = ft_substr(str, 0, 5);
	printf("Test 4 - Expected 'Hello': %s\n", result);
	free(result);

	return (0);
}
*/