/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:58:57 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/17 00:01:07 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    usage()
{
        ft_putendl_fd("Unavailable syntax", 1);
        ft_putendl_fd("./fractol mandelbrot (or 1)", 1);
        ft_putendl_fd("./fractol julia (or 2) <real_part> <imaginary_part>", 1);
        exit(1);
}

int    ft_close(int keycode, t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->win);
    //mlx_clear_window(fractal->mlx, fractal->win);
    mlx_destroy_window(fractal->mlx, fractal->win);
    exit(1);
}