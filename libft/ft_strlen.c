/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:28:29 by ndabbous          #+#    #+#             */
/*   Updated: 2024/11/25 18:54:14 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (*str && str[i] != '\0')
		i++;
	return (i);
}
/*#include <stdio.h>
int	main()
{
	char	*str = "0123456789";
	printf("%d\n", ft_strlen(str));
	return (0);
}*/
