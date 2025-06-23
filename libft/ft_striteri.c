/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:00:09 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:38:26 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
#include <ctype.h>

// Exemple de fonction à appliquer
void	to_upper_even_index(unsigned int index, char *c)
{
	if (index % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32; // Convertit en majuscule
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int	main(void)
{
	char str[] = "hello world";

	printf("Avant : %s\n", str);
	ft_striteri(str, to_upper_even_index);
	// Appliquer to_upper_even_index sur chaque caractère
	printf("Après : %s\n", str);

	return (0);
}
*/