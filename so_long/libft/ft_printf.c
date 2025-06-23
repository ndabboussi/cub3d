/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:05:28 by pde-vara          #+#    #+#             */
/*   Updated: 2024/12/20 15:13:23 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_casparcas(va_list arg, char i)
{
	void	*ptr;

	if (i == '%')
		return (ft_putchar_printf('%'), 1);
	if (i == 'c')
		return (ft_putchar_printf(va_arg(arg, int)), 1);
	if (i == 's')
		return (ft_putstr_printf(va_arg(arg, char *)));
	if (i == 'd' || i == 'i')
		return (ft_putnbr_printf(va_arg(arg, int)));
	if (i == 'u')
		return (ft_pbase_printf(va_arg(arg, unsigned int), "0123456789"));
	if (i == 'x')
		return (ft_pbase_printf(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (i == 'X')
		return (ft_pbase_printf(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (i == 'p')
	{
		ptr = va_arg(arg, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2), 2 + ft_pbase_printf((unsigned long)ptr,
				"0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] == '%')
		{
			len += ft_casparcas(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_printf(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
/*
int	main(void)
{
	int	i;

	i = printf(" je suis un Percent: %w%\n");
	printf("%d", i);
	i = ft_printf(" je suis un Percent: %w%");
	printf("%d", i);
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Pointer: %p\n", &main);
	ft_printf("Integer: %d\n", -42);
	ft_printf("Unsigned: %u\n", -42);
	ft_printf("Hex lower: %x\n", -255);
	ft_printf("Hex upper: %X\n", -255);
	ft_printf("Percent: %%\n");
	i = printf(" %p %x %X %u %d    ", "4", -1, -1, -1, 29496729);
	printf("%d", i);
	printf("\n");
	i = ft_printf(" %p %x %X %u %d    ", "4", -1, -1, -1, 29496729);
	printf("%d", i);
	return (0);
}
*/
