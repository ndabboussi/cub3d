/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:10:25 by pde-vara          #+#    #+#             */
/*   Updated: 2024/12/03 18:05:14 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab, int index)
{
	while (index > 0)
		free(tab[--index]);
	free(tab);
	return ;
}

static int	count_words(const char *str, char sep)
{
	int	i;
	int	nbw;

	i = 0;
	nbw = 0;
	if (sep != str[i] && str[i])
		nbw++;
	while (str[i])
	{
		if (sep == str[i] && str[i + 1] && sep != str[i + 1])
			nbw++;
		i++;
	}
	return (nbw);
}

static char	**split_str(char **tab, const char *str, char sep, int index)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] && sep != str[i])
		i++;
	len = i;
	tab[index] = malloc(sizeof(char) * (len + 1));
	if (!tab[index])
	{
		ft_free(tab, index);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		tab[index][i] = str[i];
		i++;
	}
	tab[index][i] = '\0';
	(index)++;
	return (tab);
}

static char	**create_tab(char **tab, const char *str, char sep, int nbw)
{
	int	i;
	int	index;

	i = ((index = 0));
	while (str[i] && index < nbw)
	{
		if (str[i] && sep == str[i])
			i++;
		if (str[i] && sep != str[i])
		{
			if (!split_str(tab, &str[i], sep, index))
				return (NULL);
			index++;
			while (str[i] && sep != str[i])
				i++;
		}
	}
	tab[nbw] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbw;

	if (!s)
		return (NULL);
	nbw = count_words(s, c);
	tab = malloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (NULL);
	if (!create_tab(tab, s, c, nbw))
		return (NULL);
	return (tab);
}
/*
//mainnnnnnnnnnnnnnnnnnnnnnn

// Fonction pour afficher le tableau de chaînes
void	print_split(char **result)
{
	int i = 0;
	if (!result)
	{
		printf("NULL\n");
		return;
	}
	while (result[i])
	{
		printf("result[%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	printf("NULL\n");
}

// Implémentation de free_split pour libérer le tableau de chaînes
static void free_s(char **result, int count) {
	int i = 0;
	while (i < count) {
		free(result[i]);
		i++;
	}
	free(result);
}

int main(void) 
{
	// Tests
	printf("Test 1: Chaîne normale avec espaces\n");
	char **result1 = ft_split("hello world this is 42", ' ');
	print_split(result1);
	free_s(result1, 5); // On libère 5 mots

	printf("\nTest 2: Chaîne avec délimiteurs multiples\n");
	char **result2 = ft_split("hello,,,world", ',');
	print_split(result2);
	free_s(result2, 2); // On libère 2 mots

	printf("\nTest 3: Chaîne avec délimiteurs au début et à la fin\n");
	char **result3 = ft_split(",hello,world,", ',');
	print_split(result3);
	free_s(result3, 2); // On libère 2 mots

    printf("\nTest 4: Chaîne vide\n");
    char **result4 = ft_split("", ',');
    print_split(result4);
    free_s(result4, 0); // Pas de mot à libérer

    printf("\nTest 5: Délimiteur absent dans la chaîne\n");
    char **result5 = ft_split("singleword", ',');
    print_split(result5);
    free_s(result5, 1); // On libère 1 mot

    printf("\nTest 6: Délimiteur unique dans la chaîne\n");
    char **result6 = ft_split(",", ',');
    print_split(result6);
    free_s(result6, 0); // Pas de mot à libérer

    printf("\nTest 7: pas de delimiteur\n");
    char **result7 = ft_split("bonjour", 0);
    print_split(result7);
    free_s(result7, 0); // Pas de mot à libérer
    return 0;
}*/