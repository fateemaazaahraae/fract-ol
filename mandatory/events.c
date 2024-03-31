/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:07:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/29 17:07:57 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	mouse_input(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == SCROLL_DOWN || mousecode == SCROLL_UP)
	{
		if (mousecode == SCROLL_DOWN)
			fractal->zoom *= 1.1;
		else
			fractal->zoom /= 1.1;
		draw(fractal);
	}
	return (0);
}
