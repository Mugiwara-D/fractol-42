/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:47:10 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/30 15:47:35 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static void	ncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*make_tab(char **tab, char *str, char c, unsigned int count)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (str[j] && str[j] == c)
			j++;
		len = 0;
		while (str[j + len] && !(str[j + len] == c))
			len++;
		tab[i] = malloc(sizeof(*tab[i]) * (len + 1));
		if (!(tab[i]))
			return (ft_free(tab, count), NULL);
		ncpy(tab[i], &str[j], len);
		j += len;
		i++;
	}
	return (*tab);
}

static int	make_wrdcount(char *str, char c)
{
	unsigned int	i;
	unsigned int	wdlen;
	unsigned int	wdcount;

	i = 0;
	wdcount = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		wdlen = 0;
		while (str[i + wdlen] && !(str[i + wdlen] == c))
			wdlen++;
		if (wdlen)
			wdcount++;
		i += wdlen;
	}
	return (wdcount);
}

char	**ft_split(const char *s, char c)
{
	char			**tab;
	unsigned int	wordcount;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	wordcount = make_wrdcount(str, c);
	tab = malloc(sizeof(*tab) * (wordcount + 1));
	if (!tab)
		return (NULL);
	*tab = make_tab(tab, str, c, wordcount);
	tab[wordcount] = 0;
	return (tab);
}
