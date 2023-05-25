/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:16:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/25 14:58:50 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>
#include <math.h>

int	red(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)(255 * n);
	g = (unsigned char)(69 * n);
	b = (unsigned char)(42 * n);
	return ((r << 16) | (g << 8) | b);
}

int	green(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)(42 * n);
	g = (unsigned char)(255 * n);
	b = (unsigned char)(69 * n);
	return ((r << 16) | (g << 8) | b);
}

int	blue(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)(42 * n);
	g = (unsigned char)(69 * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);
}

int	gris(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)(150 * n);
	g = (unsigned char)(150 * n);
	b = (unsigned char)(150 * n);
	return ((r << 16) | (g << 8) | b);
}

int	lsd(int i, double n)
{
	if (i % 3 == 1)
		return (red(i, 1.3 * n));
	if (i % 3 == 2)
		return (red(i, 1.6 * n));
	if (i % 3 == 3)
		return (red(i, 1.9 * n));
	return (gris(i, n));
}
