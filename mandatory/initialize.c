/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:50:13 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 14:57:54 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_fractal(t_fractal *fractal)
{
    fractal->x = 0;
    fractal->y = 0;
    fractal->iteration = 0;
    fractal->color = 0xABCDEF;
}

void	init_mlx(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
        exit(1);
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->set_name);
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bit_per_pixel, &fractal->size_line, &fractal->endian);
}