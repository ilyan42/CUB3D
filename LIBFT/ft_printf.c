/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:23:10 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/11 18:42:28 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_print_hexa(va_arg(arg, unsigned int), c);
	else if (c == 'p')
		count += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	if (write(1, 0, 0) == -1)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_print(arg, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
