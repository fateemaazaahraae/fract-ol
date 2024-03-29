/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:58:57 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/29 12:20:51 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(int i)
{
	if (i == 1)
		ft_putendl_fd("\x1b[31mReal Imaginary should be in [-2,2]\x1b[0m",
			1);
	else if (i == 2)
		ft_putendl_fd("\x1b[31mEnter the two parameters of Julia\x1b[0m",
			1);
	else if (i == 3)
		ft_putendl_fd("\x1b[31mEnter a valid julia args !\x1b[0m", 1);
	else
	{
		ft_putendl_fd("\x1b[31mUsage: ./fractol_bonus <fractal>\x1b[0m\n", 1);
		ft_putendl_fd("\t\x1b[31m Available fractals : \x1b[0m", 1);
		ft_putendl_fd("\t\x1b[31m - mandelbrot (or 1) -\x1b[0m", 1);
		ft_putendl_fd("\t\x1b[31m   - julia (or 2) -\x1b[0m", 1);
	}
	exit(1);
}

int	ft_close(t_fractal *fractal)
{
	ft_putendl_fd("Closing the window...", 1);
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}
