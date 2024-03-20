/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:58:57 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 15:53:21 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    usage()
{
        ft_putendl_fd("Unavailable syntax", 1);
        ft_putendl_fd("\t./fractol mandelbrot (or 1)", 1);
        ft_putendl_fd("\t./fractol julia (or 2) <real_part> <imaginary_part>", 1);
        exit(1);
}

int    ft_close(t_fractal *fractal)
{
    //ft_putendl_fd("Closing...", 1);
    mlx_destroy_image(fractal->mlx, fractal->img);
    mlx_destroy_window(fractal->mlx, fractal->win);
    exit(0);
}