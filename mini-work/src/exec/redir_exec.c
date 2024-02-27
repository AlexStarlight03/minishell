/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:14:12 by adube             #+#    #+#             */
/*   Updated: 2024/02/27 13:09:36 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    redirections(t_mini *mini, t_tokens *tok, int type)
{
    if (type == TRUNC)
       mini->fdout = open(tok->data, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    else if (type == APPEND)
        mini->fdout = open(tok->data, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    // clean close and error message if mini->fdout == -1
    dup2(mini->fdout, STDOUT);
}