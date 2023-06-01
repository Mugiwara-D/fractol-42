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
	g = (unsigned char)((10 / n) * n);
	b = (unsigned char)((60 / n) * n);
	return ((r << 16) | (g << 8) | b);
}

int	green(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)((10 / n) * n);
	g = (unsigned char)(255 * n);
	b = (unsigned char)((60 / n) * n);
	return ((r << 16) | (g << 8) | b);
}

int	blue(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)((90 / n) * n);
	g = (unsigned char)((10 / n) * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);
}

int	gris(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void) i;
	r = (unsigned char)(255 * n);
	g = (unsigned char)(255 * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);

}

int	lsd(int i, double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(((255 << (i % 16)) * n) * n);
	g = (unsigned char)(((255 << (i % 8)) * n) * n);
	b = (unsigned char)(((255 << (i % 24)) * n) * n);
	return ((r << 16) | (g << 8) | b);
}
