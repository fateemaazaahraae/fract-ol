/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:07:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/28 22:54:40 by fbazaz           ###   ########.fr       */
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
	if (keycode == 83)
		change_color(fractal, 83);
	if (keycode == 84)
		change_color(fractal, 84);
	if (keycode == 85)
		change_color(fractal, 85);
	if (keycode == 86)
		change_color(fractal, 86);
	if (keycode == 87)
		change_color(fractal, 87);
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
