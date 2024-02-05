/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:26:31 by adube             #+#    #+#             */
/*   Updated: 2024/02/05 12:02:40 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ctrl_d(int signal)
{
	(void)signal;
	//rl_clear_history();  //linking error with this function, makes it so ctrl-c does not appear on the command line (voir note makefile)
    //free everything that needs to be freed (structs and env)
	exit(3);
}

void    ctrl_c(int signal)
{
    (void)signal;
	printf("\n");
	//rl_replace_line("", 0);    //linking error with this function, makes it so ctrl-c does not appear on the command line (voir note makefile)
	rl_on_new_line();
	rl_redisplay();
}