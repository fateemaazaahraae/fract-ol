/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:39:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/30 14:38:51 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct vars
{
	int		i;
	int		sign;
	int		exponent;
	double	num;
}			t_vars;

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putendl_fd(char *s, int fd);
char		*ft_tolower(char *str);
double		ft_atof(char *str);
int			ft_isdigit(int c);

#endif