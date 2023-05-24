/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:08:54 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/28 12:47:19 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*dst;

	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2) + 1;
		dst = malloc(l * sizeof(char));
		if (!dst)
			return (NULL);
		ft_strlcpy(dst, s1, l);
		ft_strlcat(dst, s2, l);
		return (dst);
	}
	else
		return (NULL);
}
