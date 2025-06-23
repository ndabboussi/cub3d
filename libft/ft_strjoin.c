/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:13:14 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 16:15:48 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*copy;

	size = ft_strlen(s1) + ft_strlen(s2);
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

/*#include <stdio.h>
int	main()
{
	char const	s1[4] = "0123";
	char const	s2[6] = "456789";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
