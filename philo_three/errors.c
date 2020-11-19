/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:58:49 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 16:58:55 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		error_arguments(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int		malloc_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}
