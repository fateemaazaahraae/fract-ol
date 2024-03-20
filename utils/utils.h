/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:39:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/03/19 15:37:01 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl_fd(char *s, int fd);
char	*ft_tolower(char *str);

#endif