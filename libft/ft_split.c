/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:10:52 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/25 18:44:33 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_strlen_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_print_words(char *tab, const char *s, char c)
{
	int	i;
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	tab = (char *)ft_calloc(sizeof(char), len + 2);
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static int	ft_count_words(char const *s, char c)
{
	int	cpt;
	int	i;

	cpt = 0;
	i = 0;
	if (s == NULL)
		return (0);
	if (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			cpt++;
		}
		else
			i++;
	}
	return (cpt);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;

	len = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s && *s && i < len)
	{
		if (*s != c)
		{
			tab[i] = ft_print_words(tab[i], s, c);
			if (!tab[i])
			{
				ft_free(tab);
				return (0);
			}
			s += ft_strlen_words(s, c);
			i++;
		}
		s++;
	}
	return (tab[i] = NULL, tab);
}

/*int	main()
{
	//int	i = 0;
	char	*s = NULL;

	char **dest = ft_split(s, 'k');
	//char **dest2 = ft_split("", 'k');
	printf("%p\n", dest);
	//while(dest[i]
	//{
	//	printf("%s\n", dest[i]);
	//	i++;
	//}
	ft_free(dest);
	return (0);
}*/
