/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:31 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/12 14:49:07 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*#include <stdio.h>
int	main()
{
	int	c = 'h';
	int	d = 5;
	int	e = 'H';
	printf("c = %d, d= %d, e= %d\n", ft_toupper(c), ft_toupper(d), ft_toupper(e));
	return (0);
}*/
