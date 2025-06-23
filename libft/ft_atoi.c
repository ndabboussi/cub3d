/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:52 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:08 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main()
{
	const char *s1 = "-540n05kkb";
	const char *s2 = "   +16";
	const char *s3 = "hg  jhk20k";
	printf("s1= %d, atoi: %d\n", ft_atoi(s1), atoi(s1));
	printf("s2= %d, atoi: %d\n", ft_atoi(s2), atoi(s2));
	printf("s3= %d, atoi: %d\n", ft_atoi(s3), atoi(s3));
	return (0);
}*/
