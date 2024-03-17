/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:57:23 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/17 01:20:49 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    calculate_julia(t_fractal *fractal, char **av)
{
    double tmp;

    fractal->c_r = atof(av[2]);
    fractal->c_i = atof(av[3]);
    fractal->z_r = (4 * fractal->x / WIDTH) - 2;
    fractal->z_i = (4 * fractal->y / HEIGHT) - 2;
    fractal->iteration = 0;
    while (fractal->iteration < 60)
    {
        if ((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i) > 4.0)
            break ;
        tmp = fractal->z_r;
        fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i) + fractal->c_r;
        fractal->z_i = (2 * tmp * fractal->z_i) + fractal->c_i;
        fractal->iteration++;
    }
    if (fractal->iteration == 60)
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, 0x000000);
    else
        mlx_pixel_put(fractal->mlx, fractal->win, fractal->x, fractal->y, 0x100101 * fractal->iteration);
}

void	draw_julia(t_fractal *fractal, char **av)
{
    fractal->x = 0;
    while  (fractal->x < WIDTH)
    {
        fractal->y = 0;
        while (fractal->y < HEIGHT)
        {
            calculate_julia(fractal, av);
            fractal->y++;
        }
        fractal->x++;
    }
    // mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}