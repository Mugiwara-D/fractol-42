/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:37:41 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/02 16:33:48 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_dstlen(long int n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		l;
	long int	nb;

	nb = n;
	l = ft_dstlen(nb);
	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (NULL);
	ret[l] = '\0';
	if (nb == 0)
		ret[0] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		ret[0] = '-';
	}
	while (l-- > 0 && nb != 0)
	{
		ret[l] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}
