/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:59:52 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/22 13:00:18 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrc;

	i = 0;
	ptrc = (unsigned char *) s;
	while (i < n)
	{
		if (ptrc[i] == (unsigned char)c)
			return ((void *) ptrc + i);
		i++;
	}
	return (NULL);
}
