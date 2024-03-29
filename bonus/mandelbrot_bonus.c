/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:50:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/28 22:33:42 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_fractal *fractal, int color)
{
	char	*dst;

	dst = fractal->addr + ((int)fractal->y * fractal->size_line
			+ (int)fractal->x * (fractal->bit_per_pixel / 8));
	*(unsigned int *)dst = color * fractal->iteration;
}

void	calculate_mandelbrot(t_fractal *fractal, int in, int out)
{
	double	tmp;

	fractal->z_r = 0.0;
	fractal->z_i = 0.0;
	fractal->c_r = (((4 * fractal->x / WIDTH) - 2) * fractal->zoom)
		+ fractal->offset_x;
	fractal->c_i = (((4 * fractal->y / HEIGHT) - 2) * fractal->zoom)
		+ fractal->offset_y;
	fractal->iteration = 0;
	while (fractal->iteration < fractal->max_iteration)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i
				* fractal->z_i) + fractal->c_r;
		fractal->z_i = (2 * tmp * fractal->z_i) + fractal->c_i;
		if ((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i) > 4.0)
			break ;
		fractal->iteration++;
	}
	if (fractal->iteration == fractal->max_iteration)
		my_mlx_pixel_put(fractal, in);
	else
		my_mlx_pixel_put(fractal, out);
}

void	draw_mandelbrot(t_fractal *fractal, int in, int out)
{
	fractal->x = 0.0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_mandelbrot(fractal, in, out);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
