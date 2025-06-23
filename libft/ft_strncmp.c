/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:58:13 by pde-vara          #+#    #+#             */
/*   Updated: 2024/11/27 14:21:02 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*cast au cas ou caractere non ascii comme tilde

int	main()
{
	char	str1[] = "VBNrmld*gm;*S";
	char	str2[] = "VBNrmld&gm;*S";
	printf("%d\n", ft_strncmp(str1, str2, 8));
	printf("%d", strncmp(str1, str2, 8));
}
*/