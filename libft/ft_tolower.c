/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:02 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/12 15:03:53 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*#include <stdio.h>
int	main()
{
	int	c = 'H';
	int	d = 10;
	int	e = 'j';
	printf("c= %d, d= %d, e= %d\n", ft_tolower(c), ft_tolower(d), ft_tolower(e));
	return (0);
}*/
