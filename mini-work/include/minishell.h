/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:36 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 13:53:26 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>

# define CD 10
# define ECHO 11
# define ENV 12
# define EXIT 13
# define EXPORT 14
# define PWD 15
# define UNSET 16

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//changer nom = changer everywhere
typedef struct	s_env
{
	char			*content;
	struct s_env	*next;
}				t_env;

typedef struct s_mini
{
	int				fdin;
	int				fdout;
	t_env			*env;
}				t_mini;

#endif
