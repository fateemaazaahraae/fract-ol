/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:30:27 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/27 13:32:46 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	initialize_variables(t_vars *vars)
{
	vars->i = 0;
	vars->num = 0.0;
	vars->sign = 1;
	vars->exponent = 0;
}

double	ft_atof(char *str)
{
	t_vars	vars;

	initialize_variables(&vars);
	while (str[vars.i] == ' ' || str[vars.i] == '\t')
		vars.i++;
	if (str[vars.i] == '-' || str[vars.i] == '+')
	{
		if (str[vars.i] == '-')
			vars.sign = -1;
		vars.i++;
	}
	while (str[vars.i] && ft_isdigit(str[vars.i]))
		vars.num = vars.num * 10 + (str[vars.i++] - '0');
	if (str[vars.i] == '.')
	{
		vars.i++;
		while (str[vars.i] && ft_isdigit(str[vars.i]))
		{
			vars.num = vars.num * 10 + (str[vars.i++] - '0');
			vars.exponent++;
		}
	}
	while (vars.exponent-- > 0)
		vars.num = vars.num / 10;
	return (vars.num * vars.sign);
}
