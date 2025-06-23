/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:23:26 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 13:47:46 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;
	char			*copy;

	copy = (char *)s;
	d = (unsigned char)c;
	i = 0;
	while (copy[i])
	{
		if (copy[i] == d)
			return (&copy[i]);
		i++;
	}
	if (d == '\0' && copy[i] == '\0')
		return (&copy[i]);
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	const char	*s1 = "abcdefghi";
	int	c = 'h';
	int	d = '\0';
	int	e = 'k';
	printf("c= %s\n", ft_strchr(s1, c));
	printf("d= %s\n", ft_strchr(s1, d));
	printf("e= %s\n", ft_strchr(s1, e));
	return (0);
}*/
