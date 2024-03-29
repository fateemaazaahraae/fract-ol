/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:34:21 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/29 12:58:35 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int check_julia_args(char *str)
{
    int i;
    int flag;
    
    i = 0;
    flag = 0;
    while (str[i] == '-' || str[i] == '+')
    {
        flag++;
        i++;
    }
    if (flag > 1)
        return (flag);
    flag = 0;
    while (str[i])
    {
        if (str[i] == '.')
            flag++;
        if (str[i] == ',')
            return (10);
        i++;
    }
    return (flag);
}

void	check_arguments(int ac, char **av, t_fractal *fractal)
{
	if ((ft_strcmp(ft_tolower(av[1]), "mandelbrot") == 0 || ft_strcmp(av[1],
				"1") == 0) && ac == 2)
		fractal->set_name = "Mandelbrot set";
	else if ((ft_strcmp(ft_tolower(av[1]), "julia") == 0) || (ft_strcmp(av[1],
					"2") == 0))
	{
		if (ac != 4)
			usage(2);
        if (check_julia_args(av[2]) > 1 || check_julia_args(av[3]) > 1)
            usage(3);
		fractal->set_name = "Julia set";
		fractal->c_re = ft_atof(av[2]);
		fractal->c_im = ft_atof(av[3]);
		if (fractal->c_re > 2 || fractal->c_re < -2 || fractal->c_im > 2
			|| fractal->c_im < -2)
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
