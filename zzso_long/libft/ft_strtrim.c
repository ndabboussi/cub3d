/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:18:57 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/28 12:20:04 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char s, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		debu;
	size_t		fin;
	size_t		i;
	char		*new;

	if (!s1 || !set)
		return (NULL);
	debu = 0;
	while (s1[debu] && is_set(s1[debu], (char *)set))
		debu++;
	fin = ft_strlen(s1);
	while (fin > debu && is_set(s1[fin - 1], (char *)set))
		fin--;
	new = (char *)malloc((fin - debu + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < fin - debu)
	{
		new[i] = s1[debu + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	char		*result;

	result = ft_strtrim("  Hello World  ", " ");
	printf("Result 1: '%s'\n", result);
	free(result); // Cas 1 : caractères de 'set' au début et à la fin

	result = ft_strtrim("xxxyHello World", "xy");
	printf("Result 2: '%s'\n", result);
	free(result); // Cas 2 : caractères de 'set' uniquement au début

	result = ft_strtrim("Hello Worldyyy", "xy");
	printf("Result 3: '%s'\n", result);
	free(result); // Cas 3 : caractères de 'set' uniquement à la fin

	result = ft_strtrim("Hello World", "xyz");
	printf("Result 4: '%s'\n", result);
	free(result); // Cas 4 : aucun caractère de 'set' dans la chaîne

	result = ft_strtrim("aaaaa", "a");
	printf("Result 5: '%s'\n", result);
	free(result); // Cas 5 : chaîne composée uniquement de caractères de 'set'

	result = ft_strtrim("", "xyz");
	printf("Result 6: '%s'\n", result);
	free(result); // Cas 6 : chaîne vide

	result = ft_strtrim("Hello World", "");
	printf("Result 7: '%s'\n", result);
	free(result);
	return (0); // Cas 7 : chaîne à découper vide
}*/