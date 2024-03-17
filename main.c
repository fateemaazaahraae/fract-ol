/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:49:53 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/17 01:10:19 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    check_arguments(int ac, char **av, t_fractal *fractal)
{
    if ((ft_strcmp(av[1], "mandelbrot") == 0 || ft_strcmp(av[1], "1") == 0) && ac == 2)
        fractal->set_name = "Mandelbrot set";
    else if ((ft_strcmp(av[1], "julia") == 0 || ft_strcmp(av[1], "2") == 0) && ac == 4)
        fractal->set_name = "Julia set";
    else
        usage();
}

void    draw(t_fractal *fractal, char **av)
{
    if (ft_strcmp(fractal->set_name, "Mandelbrot set") == 0)
        draw_mandelbrot(fractal);
    else if (ft_strcmp(fractal->set_name, "Julia set") == 0)
        draw_julia(fractal, av);
   
}

int main(int ac, char **av)
{
    t_fractal fractal;

    if (ac < 2)
        usage();
    check_arguments(ac, av, &fractal);
    init_mlx(&fractal);
    draw(&fractal, av);
    //mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
    //mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
    mlx_loop(fractal.mlx);
}