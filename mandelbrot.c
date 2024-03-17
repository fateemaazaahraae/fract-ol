/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:50:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/17 00:56:38 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	my_mlx_pixel_put(t_fractal *fractal, int color)
{
	char	*dst;

	dst = fractal->pointer_to_image + ((int)fractal->y * fractal->size_line + (int)fractal->x * (fractal->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
} */

void    calculate_mandelbrot(t_fractal *fractal)
{
    double tmp;

    fractal->z_r = 0.0;
    fractal->z_i = 0.0;
    fractal->c_r = (4 * fractal->x / WIDTH) - 2;
    fractal->c_i = (4 * fractal->y / HEIGHT) - 2;
    fractal->iteration = 0;
    while (fractal->iteration < 100)
    {
        if ((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i) > 4.0)
            break ;
        tmp = fractal->z_r;
        fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i) + fractal->c_r;
        fractal->z_i = (2 * tmp * fractal->z_i) + fractal->c_i;
        fractal->iteration++;
    }
    if (fractal->iteration == 100)
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, 0x000000);
    else
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, 0xFFFFFF);
        // my_mlx_pixel_put(fractal, 0xFFFFFF * fractal->iteration);
}

void    draw_mandelbrot(t_fractal *fractal)
{
    fractal->x = 0;
    while  (fractal->x < WIDTH)
    {
        fractal->y = 0;
        while (fractal->y < HEIGHT)
        {
            calculate_mandelbrot(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
    // mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
