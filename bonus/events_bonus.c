/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:07:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/30 14:35:26 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_color(t_fractal *fractal, int color)
{
	if (color == 83)
		fractal->color = R;
	if (color == 84)
		fractal->color = S;
	if (color == 85)
		fractal->color = Y;
	if (color == 86)
		fractal->color = B;
	if (color == 87)
		fractal->color = P;
	draw(fractal);
}

void	arrow_keys(t_fractal *fractal, int keycode)
{
	if (keycode == 123)
		fractal->offset_x -= 0.1;
	if (keycode == 124)
		fractal->offset_x += 0.1;
	if (keycode == 125)
		fractal->offset_y += 0.1;
	if (keycode == 126)
		fractal->offset_y -= 0.1;
	draw(fractal);
}

int	key_input(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		ft_close(fractal);
	if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86
		|| keycode == 87)
		change_color(fractal, keycode);
	if (keycode == 69 || keycode == 78)
	{
		if (keycode == 69)
			fractal->max_iteration += 5;
		else
			fractal->max_iteration -= 5;
		draw(fractal);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		arrow_keys(fractal, keycode);
	if (keycode == 49)
	{
		init_fractal(fractal);
		draw(fractal);
	}
	return (0);
}

int	mouse_input(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (button == 4 || button == 5)
	{
		if (button == 5)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		fractal->zoom *= zoom_factor;
		mouse_x = ((4 * x / WIDTH) - 2) * fractal->zoom;
		mouse_y = ((4 * y / HEIGHT) - 2) * fractal->zoom;
		fractal->offset_x = (fractal->offset_x + mouse_x) - (mouse_x
				* zoom_factor);
		fractal->offset_y = (fractal->offset_y + mouse_y) - (mouse_y
				* zoom_factor);
		draw(fractal);
	}
	return (0);
}
