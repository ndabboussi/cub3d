/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:42:22 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/19 18:17:01 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	int	cpt;

	cpt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cpt = 1;
	while (n != 0)
	{
		n = n / 10;
		cpt++;
	}
	return (cpt);
}

char	*ft_itoa(int n)
{
	long int	bis;
	int			len;
	char		*tab;

	bis = n;
	len = ft_intlen(bis);
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	if (bis == 0)
		tab[0] = '0';
	if (bis < 0)
	{
		tab[0] = '-';
		bis = -bis;
	}
	tab[len] = '\0';
	while (bis > 0)
	{
		tab[len - 1] = bis % 10 + 48;
		bis = bis / 10;
		len--;
	}
	return (tab);
}

/*int main()
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(6677));
	printf("%s\n", ft_itoa(-2578));
	return (0);
}*/
