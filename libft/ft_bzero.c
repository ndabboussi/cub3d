/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:50 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:40:03 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
int	main()
{
	char	str[] = "test pour voir";

	printf("Avant ft_bzero: %s\n", str);
	ft_bzero(str, 3);
	printf("Après ft_bzero: %s\n", str); // Affichera une chaîne vide avant 't'

	// Pour afficher les 10 premiers caractères de la chaîne, même avec des '\0':
	printf("Affichage partiel: %.10s\n", str);

	return 0;
}*/