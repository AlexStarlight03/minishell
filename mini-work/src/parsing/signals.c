/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:26:31 by adube             #+#    #+#             */
/*   Updated: 2024/02/08 09:21:56 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ctrl_d(int signal)
{
	(void)signal;
	rl_clear_history();
    //free everything that needs to be freed (structs and env)
	exit(3);
}

void    ctrl_c(int signal)
{
    (void)signal;
	printf("\n");
	rl_replace_line(" ", 0); // why is it not working, a regler
	rl_on_new_line();
	rl_redisplay();
}