/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:49:02 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/27 12:16:58 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenb(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int		len;
	unsigned int		n2;
	char				*asci;

	len = lenb(n);
	asci = malloc(len + 1);
	if (!asci)
		return (NULL);
	asci[len] = '\0';
	if (n == 0)
		asci[0] = '0';
	if (n < 0)
	{
		asci[0] = '-';
		n2 = -n;
	}
	else
		n2 = n;
	while (n2 > 0)
	{
		asci[len - 1] = (n2 % 10) + '0';
		n2 = n2 / 10;
		len--;
	}
	return (asci);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(56 * 4));
	printf("%s\n", ft_itoa(1000));
	printf("%s\n", ft_itoa(-345678));
	return (0);
}*/