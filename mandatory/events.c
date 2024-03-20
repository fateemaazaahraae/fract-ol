/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:07:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 23:49:25 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void    print_events(t_fractal *fractal, int color)
{
    fractal->color = color;
} */
int key_input(int keycode, t_fractal *fractal)
{
    if (keycode == ESC)
    {
        ft_putendl_fd("Closing using ESC button...", 1);
        ft_close(fractal);
    }
    /* if (keycode == 9)
    {
        ft_putendl_fd("switching to julia", 1);
        fractal->c_r = 0;
        fractal->c_i = 0.8;
        draw_julia(fractal, BLACK, 0x008000);
    } */
    if (keycode == R || keycode == S || keycode == B || keycode == G || keycode == Y)
    {
        ft_putendl_fd("You have changed the color of the set", 1);
        if (keycode == R) //red
            fractal->color = RED;
        if (keycode == S) //selver
            fractal->color = SELVER;
        if (keycode == B) //brown
            fractal->color = BROWN;
        if (keycode == G) //green
            fractal->color = GREEN;
        if (keycode == Y) //yellow
            fractal->color = YELLOW;
        draw(fractal);
    }
    return (0);
}
