/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:50:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/27 16:47:22 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_tricorn(t_fractal *fractal, int in, int out)
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
		fractal->z_i = (-2 * tmp * fractal->z_i) + fractal->c_i;
		if ((fractal->z_r * fractal->z_r) + (fractal->z_i * fractal->z_i) > 4.0)
			break ;
		fractal->iteration++;
	}
	if (fractal->iteration == fractal->max_iteration)
		my_mlx_pixel_put(fractal, in);
	else
		my_mlx_pixel_put(fractal, out);
}

void	draw_tricorn(t_fractal *fractal, int in, int out)
{
	fractal->x = 0.0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_tricorn(fractal, in, out);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
