/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:26:31 by adube             #+#    #+#             */
/*   Updated: 2024/02/25 23:02:01 by mchampag         ###   ########.fr       */
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
	if (signal != 100)
		printf("\n");
	rl_replace_line(" ", 0); // why is it not working, a regler
	rl_on_new_line();
	rl_redisplay();
}

void signals_activation(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
