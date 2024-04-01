/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:32:39 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 21:12:26 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../utils/utils.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700

# define ESC 53
# define BLACK 0x000000
# define R 0x100101
# define S 0xEDFFFF
# define Y 0x111100
# define B 0x001111
# define P 0x110011

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	int		iteration;
	int		max_iteration;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	char	*set_name;
}			t_fractal;

void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	check_arguments(int ac, char **av, t_fractal *fractal);
void	draw(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal, int in, int out);
void	calculate_julia(t_fractal *fractal, int in, int out);
void	draw_mandelbrot(t_fractal *fractal, int in, int out);
void	draw_julia(t_fractal *fractal, int in, int out);
void	usage(int i);
int		ft_close(t_fractal *fractal);
int		key_input(int keycode, t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *fractal, int color);
int		mouse_input(int mousecode, int x, int y, t_fractal *fractal);
void	change_color(t_fractal *fractal, int color);
void	arrow_keys(t_fractal *fractal, int keycode);
void	menu(void);
int		check_julia_args(char *str);
int		norminette(char *str);

#endif