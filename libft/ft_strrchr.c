/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:25:31 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 13:46:49 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*copy;
	unsigned char	d;

	i = ft_strlen(s);
	d = (unsigned char)c;
	copy = (char *)s;
	while (i != 0)
	{
		if (copy[i] == d)
			return (&copy[i]);
		i--;
	}
	if (copy[i] == d)
		return (&copy[i]);
	return (NULL);
}

/*#include <stdio.h>
int     main()
{
        const char      *s1 = "a5bc5ef5h";
        int     c = '5';
        int     d = '\0';
        int     e = 'a';
        printf("c= %s\n", ft_strrchr(s1, c));
        printf("d= %s\n", ft_strrchr(s1, d));
        printf("e= %s\n", ft_strrchr(s1, e));
        return (0);
}*/
