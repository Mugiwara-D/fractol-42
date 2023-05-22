/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:27:44 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/05 11:19:31 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*r;

	if (!s)
		return (NULL);
	r = ft_strdup(s);
	if (!r)
		return (NULL);
	i = 0;
	while (r[i])
	{
		r[i] = (*f)(i, r[i]);
		i++;
	}
	return (r);
}
