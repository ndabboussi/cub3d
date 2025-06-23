/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:45:35 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/27 13:49:18 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strchr("bonsoir", 'o'));
	// Affiche "onsir"
	printf("%s\n", ft_strchr("bonsoir", 'z'));
	// Affiche "(null)" car 'z' n'est pas dans la chaîne
	printf("%s\n", ft_strchr("bonsoir", '\0'));
	// Affiche "" car c'est la fin de la chaîne
	return (0);
}
*/