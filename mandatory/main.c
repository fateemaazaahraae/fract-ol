/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:49:53 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 23:38:39 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    check_arguments(int ac, char **av, t_fractal *fractal)
{
    if ((ft_strcmp(ft_tolower(av[1]), "mandelbrot") == 0 || ft_strcmp(av[1], "1") == 0) && ac == 2)
        fractal->set_name = "Mandelbrot set";
    else if ((ft_strcmp(ft_tolower(av[1]), "julia") == 0 || ft_strcmp(av[1], "2") == 0) && ac == 4)
    {
        fractal->set_name = "Julia set";
        fractal->c_r = atof(av[2]);
        fractal->c_i = atof(av[3]);
    }
    else
        usage();
}

void    draw(t_fractal *fractal)
{
    if (ft_strcmp(fractal->set_name, "Mandelbrot set") == 0)
        draw_mandelbrot(fractal, BLACK, fractal->color);
    else if (ft_strcmp(fractal->set_name, "Julia set") == 0)
        draw_julia(fractal, BLACK, fractal->color);
   
}

int main(int ac, char **av)
{
    t_fractal fractal;

    if (ac < 2)
        usage();
    check_arguments(ac, av, &fractal);
    init_mlx(&fractal);
    init_fractal(&fractal);
    draw(&fractal);
    mlx_key_hook(fractal.win, key_input, &fractal);
    mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
    mlx_loop(fractal.mlx);
}
