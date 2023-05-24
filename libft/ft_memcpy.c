/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:41 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/22 12:58:17 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*tsrc;
	char		*tdest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tsrc = (const char *)src;
	tdest = (char *) dest;
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	dest = (void *) tdest;
	return (dest);
}
