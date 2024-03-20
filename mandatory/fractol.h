/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:32:39 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 23:46:10 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700

// key_codes
# define ESC 53
# define R 15
# define S 1
# define Y 16
# define B 11
# define G 5

// colors
# define BLACK 0x000000
# define RED 0x100101
# define SELVER 0x222324
# define BROWN 0x211236
# define PURPLE 0xA020F0
# define GREEN 0x008000
# define YELLOW 0xFFFFAB

// mouse_codes
# define SCROLL_UP 4
# define SCROLL_DOWN 5



typedef struct fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *addr;
    int     bit_per_pixel;
    int     size_line;
    int     endian;
    int     iteration;
    int     color;
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


void    init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void    check_arguments(int ac, char **av, t_fractal *fractal);
void    draw(t_fractal *fractal);
void    calculate_mandelbrot(t_fractal *fractal, int in, int out);
void    calculate_julia(t_fractal *fractal, int in, int out);
void    draw_mandelbrot(t_fractal *fractal, int in, int out);
void	draw_julia(t_fractal *fractal, int in, int out);
void    usage();
int     ft_close(t_fractal *fractal);
int     key_input(int keycode, t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *fractal, int color);

#endif