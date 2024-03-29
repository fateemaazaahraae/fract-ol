/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:49:53 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/28 23:06:00 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	check_arguments(int ac, char **av, t_fractal *fractal)
{
	if ((ft_strcmp(ft_tolower(av[1]), "mandelbrot") == 0 || ft_strcmp(av[1],
				"1") == 0) && ac == 2)
		fractal->set_name = "Mandelbrot set";
	else if (((ft_strcmp(ft_tolower(av[1]), "julia") == 0) || (ft_strcmp(av[1],
					"2") == 0)))
	{
		if (ac != 4)
			usage(2);
		fractal->set_name = "Julia set";
		fractal->c_r = ft_atof(av[2]);
		fractal->c_i = ft_atof(av[3]);
		if (fractal->c_r > 2 || fractal->c_r < -2 || fractal->c_i > 2
			|| fractal->c_i < -2)
			usage(1);
	}
	else if ((ft_strcmp(ft_tolower(av[1]), "tricorn") == 0 || ft_strcmp(av[1],
				"3") == 0) && ac == 2)
		fractal->set_name = "Tricorn set";
	else if ((ft_strcmp(ft_tolower(av[1]), "ship") == 0 || ft_strcmp(av[1],
				"4") == 0) && ac == 2)
		fractal->set_name = "Burning Ship set";
	else
		usage(0);
}

void	draw(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (ft_strcmp(fractal->set_name, "Mandelbrot set") == 0)
		draw_mandelbrot(fractal, BLACK, fractal->color);
	else if (ft_strcmp(fractal->set_name, "Julia set") == 0)
		draw_julia(fractal, BLACK, fractal->color);
	else if (ft_strcmp(fractal->set_name, "Tricorn set") == 0)
		draw_tricorn(fractal, BLACK, fractal->color);
	else if (ft_strcmp(fractal->set_name, "Burning Ship set") == 0)
		draw_burningship(fractal, BLACK, fractal->color);
}

void	menu(void)
{
	ft_putendl_fd("\n\t\x1b[33m^^^HELLO TO THE WORLD OF FRACTALS^^^\x1b[0m\n",
		1);
	ft_putendl_fd("\t\t       \x1b[33mHOW TO USE : \x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33m1/- Zoom : Scroll down or up\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33m2/- Change iterations : + or -\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33m3/- Move : arrow keys\x1b[0m", 1);
	ft_putendl_fd("\t\x1b[33m4/- Close the window : ESC or Red cross\x1b[0m",
		1);
	ft_putendl_fd("\t\x1b[33m5/- Change color : use numbers (1 -> 5)\x1b[0m",
		1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		usage(0);
	check_arguments(ac, av, &fractal);
	init_mlx(&fractal);
	init_fractal(&fractal);
	menu();
	draw(&fractal);
	mlx_key_hook(fractal.win, key_input, &fractal);
	mlx_mouse_hook(fractal.win, mouse_input, &fractal);
	mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
	mlx_loop(fractal.mlx);
}
