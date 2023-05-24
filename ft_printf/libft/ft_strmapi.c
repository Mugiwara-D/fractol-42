/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:27:44 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/28 12:50:49 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*r;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	r = malloc(i * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	r = ft_strdup(s);
	while (r[i])
	{
		r[i] = (*f)(i, r[i]);
		i++;
	}
	return (r);
}
