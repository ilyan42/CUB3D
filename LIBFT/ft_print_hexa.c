/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:15:50 by ilbendib          #+#    #+#             */
/*   Updated: 2023/12/11 18:57:25 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hexa(unsigned int nb, char const c, int *count)
{
	if (nb >= 16)
	{
		ft_put_hexa(nb / 16, c, count);
		ft_put_hexa(nb % 16, c, count);
	}
	else
	{
		if (nb <= 9)
			*count += ft_putchar(nb + 48);
		else
		{
			if (c == 'x')
				*count += ft_putchar(nb - 10 + 'a');
			else if (c == 'X')
				*count += ft_putchar(nb - 10 + 'A');
		}
	}
}

int	ft_print_hexa(unsigned int nb, char const c)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += ft_putchar('0');
	else
		ft_put_hexa(nb, c, &count);
	return (count);
}
