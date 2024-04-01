/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:15:29 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/31 21:06:01 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	norminette(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '.')
			i++;
		else if (str[i] < 48 || str[i] > 57)
		{
			flag++;
			i++;
		}
		else
			i++;
	}
	return (flag);
}

int	check_julia_args(char *str)
{
	int	i;
	int	flag;
	int	sign;

	i = 0;
	flag = 0;
	sign = 0;
	if (!str[0])
		return (42);
	while (str[i])
	{
		if (((str[i] == '.' || str[i] == '-' || str[i] == '+')
				&& !ft_isdigit(str[i + 1])) || (str[i] == '.' && i == 0))
			return (42);
		if (str[i] == '-' || str[i] == '+')
			sign++;
		if (str[i] == '.')
			flag++;
		i++;
	}
	if (flag > 1 || sign > 1)
		return (42);
	if (norminette(str) > 0)
		return (42);
	return (0);
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
	else
		usage(0);
}
