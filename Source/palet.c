/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:16:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/24 14:17:10 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>
#include <math.h>

int	red(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(255 * n);
	g = (unsigned char)(69 * n);
	b = (unsigned char)(42 * n);
	return ((r << 16) | (g << 8) | b);
}

int	green(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(42 * n);
	g = (unsigned char)(255 * n);
	b = (unsigned char)(69 * n);
	return ((r << 16) | (g << 8) | b);
}

int	blue(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(42 * n);
	g = (unsigned char)(69 * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);
}

int	gris(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(110 * n);
	g = (unsigned char)(200 * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);
}

int	lsd(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	
	r = (unsigned char)(255 * (n * (n < 0.3 && n > 0)));
	g = (unsigned char)(255 * (n * (n < 0.6 && n > 0.3)));
	b = (unsigned char)(255 * (n * (n < 0.9 && n > 0.6)));
	return ((r << 16) | (g << 8) | b);
}
