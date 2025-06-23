/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:02:03 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/21 16:45:30 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*copy;

	i = 0;
	j = 0;
	len = ft_strlen(s1) - 1;
	while (ft_check(set, s1[i]) != 0 && s1[i])
		i++;
	if (i >= len)
		return (ft_strdup(""));
	while (ft_check(set, s1[len]) != 0 && len != 0)
		len--;
	copy = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!copy)
		return (NULL);
	while (i < len + 1)
	{
		copy[j] = s1[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

/*#include <stdio.h>
int	main()
{
	char const s1[] = "ERROR-just joking-ERRORa";
	char const set[] = "ORE";
	printf("%s\n", s1);
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
