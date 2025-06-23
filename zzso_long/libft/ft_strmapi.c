/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:58:43 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/26 14:34:14 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char my_function(unsigned int i, char c)
{
    return (c + i); // Ajoute l'index au caractère
}

int main()
{
    char *str = "Hello";
    char *result = ft_strmapi(str, my_function);

    if (result)
    {
        printf("Résultat : %s\n", result); // Ex : "Hfnos"
        free(result); // Libérer la mémoire allouée
    }
    return 0;
}*/