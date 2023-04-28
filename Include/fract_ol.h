/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:24:50 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/24 16:28:12 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LF 1200
# define HF 900

# include <../minilibx-linux/mlx.h>
# include <stdlib.h>
# include <ft_printf.h>

typedef struct mlx_data
{
	void	*ptr;
	void	*win;

}	t_mlx;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct pixel_data
{
	int32_t	x;
	int32_t	y;
	int32_t	color;
}	t_pxl;

typedef struct img_data
{
	void	*img;
	char	*ptr;
	int		bpp;
	int		lil;
	int		end;
}	t_img;

typedef struct fractal_data
{
	char	*name;
	float	ymax;
	float	xmax;
	float	ymin;
	float	xmin;
	int	zoom;
	int	imax;
	
}	t_fractal;

t_img	*init_img(t_mlx *mlx);
void	draw(t_img *frame, t_pxl *p);
t_mlx	*init(void);
int		key_hook(int keycode, t_mlx *mlx);
void	my_pixel_put(t_img *data, int x, int y, int color);
int	s_cmp(char *s1, char *s2);

#endif
