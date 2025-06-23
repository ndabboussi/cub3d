/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:29:09 by pde-vara          #+#    #+#             */
/*   Updated: 2025/01/15 10:55:24 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int n)
{
	char		c;
	long int	len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar_printf('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr_printf(nb / 10);
	}
	len++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (len);
}

int	ft_pbase_printf(unsigned long int nb, char *base)
{
	unsigned long int	base_len;
	int					len;

	if (!base || !base[1])
		return (0);
	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (nb >= base_len)
	{
		len += ft_pbase_printf(nb / base_len, base);
	}
	len += ft_putchar_printf(base[nb % base_len]);
	return (len);
}
