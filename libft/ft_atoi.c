/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:56:18 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/25 18:40:19 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbfinal;
	int	signe;

	i = 0;
	nbfinal = 0;
	signe = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbfinal = (nbfinal * 10) + (nptr[i] - '0');
		i++;
	}
	return (signe * nbfinal);
}
/*
int	main(int ac, char **av)
{
	ac = ac + 0;
	printf("%d\n", ft_atoi(av[1]));
	printf("%d\n", atoi(av[1]));
}
*/