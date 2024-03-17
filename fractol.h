/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:32:39 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/17 01:07:43 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700
# define BLACK 0x00000000
# define WHITE 0xFFFFFFFF
typedef struct fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *pointer_to_image;
    int     bit_per_pixel;
    int     size_line;
    int     endian;
    int     iteration;
    double     z_r;
    double     z_i;
    double     c_r;
    double     c_i;
    double     x;
    double     y;
    char    *buf;
    char    *set_name;
}   t_fractal;

# include "../utils/utils.h"
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

void	init_mlx(t_fractal *fractal);
void    check_arguments(int ac, char **av, t_fractal *fractal);
void    draw(t_fractal *fractal, char **av);
void    calculate_mandelbrot(t_fractal *fractal);
void    calculate_julia(t_fractal *fractal, char **av);
void    draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal, char **av);
void    usage();
int    ft_close(int keycode, t_fractal *fractal);

#endif