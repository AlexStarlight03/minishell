/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:29 by mchampag          #+#    #+#             */
/*   Updated: 2024/01/19 15:40:16 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_error(int return_value, char *message)
{
	if (return_value == -1)
	{
		ft_putstr_fd_n(message, 2, 'n');
		exit(EXIT_FAILURE);
	}
	return (return_value);
}
