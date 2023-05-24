/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:31:22 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/01 17:12:28 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_is_set(const char cs, const char *set)
{
	int	n;

	n = 0;
	while (set[n])
	{
		if (set[n] == cs)
			return (1);
		n++;
	}
	return (0);
}

int	ft_mlen(const char *s, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (ft_is_set(s[i], set))
		i++;
	while (ft_is_set(s[j - 1], set))
		j--;
	return (j - i);
}

int	ft_pass(const char *s, const char *set, char c)
{
	int	i;

	i = 0;
	if (c == 's')
	{
		i = 0;
		while (ft_is_set(s[i], set) && s[i])
			i++;
	}
	else if (c == 'e')
	{
		i = ft_strlen(s);
		while (ft_is_set(s[i - 1], set) && i > 0)
			i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	int		d;
	int		f;
	int		i;

	if (!s || (!s && !set))
		return (NULL);
	else if (!set)
		return (ft_strdup(s));
	d = ft_mlen(s, set);
	if (d <= 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * d + 1);
	if (!str)
		return (NULL);
	d = ft_pass(s, set, 's');
	f = ft_pass(s, set, 'e');
	i = 0;
	while (d < f && s[d])
	{
		str[i++] = s[d];
		d++;
	}
	str[i] = '\0';
	return (str);
}	
