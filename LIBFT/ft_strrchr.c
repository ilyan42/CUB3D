/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:38:09 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/09 17:10:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp;
	char	*res;

	i = 0;
	res = 0;
	tmp = (char)c;
	while (s[i])
	{
		if (s[i] == tmp)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == tmp)
		res = (char *)&s[i];
	return (res);
}
