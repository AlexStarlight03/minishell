/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:36 by adube             #+#    #+#             */
/*   Updated: 2024/02/27 14:04:45 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 65535

# define READLINE_LIBRARY
# include "../lib/libft42/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include "readline.h"
# include "history.h"
# include "chardefs.h"
# include "keymaps.h"
# include "rlstdc.h"
# include "rltypedefs.h"
# include "tilde.h"
# include <readline/readline.h>
# include <readline/history.h> 

// # include <termios.h>



# define CD 10
# define ECHO 11
# define ENV 12
# define EXIT 13
# define EXPORT 14
# define PWD 15
# define UNSET 16

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

// typedef enum e_toktype
// {
// 	TOK_ERROR,
// 	TOK_WORD,
// 	TOK_SPACE,
// 	TOK_DIGIT,
// 	TOK_OPERATOR,
// 	TOK_REDIRECTION,
// }	t_toktype;

typedef struct s_tokens
{
	char		*data;
	int			type;
	struct s_tokens	*previous;
	struct s_tokens	*next;
}				t_tokens;

typedef struct s_delete
{
	char			*output;
	char			*str;
	int				index_i;
	int				index_j;
	int				temp;
}					t_delete;

typedef struct s_env
{
	char			*content;
	struct s_env	*next;
}				t_env;

typedef struct s_mini
{
	int				fdin;
	int				fdout;
	t_env			*env;
	char			*path;
	char			**command;
}				t_mini;

/* Main */
int		main(int argc, char **argv, char **envp);

/* Builtins */
int		cd(t_env *env, char **args);
void	ft_echo(char **args);
int		ft_env(t_env *env);
void	ft_exit(t_mini *mini, t_env *env);
int		ft_export(char **cmd, t_env *env);
int		ft_pwd(void);
bool	ft_unset(t_mini *mini, char **cmd);
char	*get_var_name(char *dest, char *src);
int		check_env(t_env *env, char *args);
char	*env_str(t_env *list);
bool	env_add_back(t_env *env, char *str);
void	free_lst_node(t_mini *mini, t_env *env);

/* Parsing */
int		is_a_builtin(char **args);
void	parse(char *input, t_env *env, t_mini *mini);
void	exec_builtin(t_mini *mini, t_env *env, char **args, int cmd);
/* signals */
void    ctrl_c(int signal);
void	ctrl_d(int signal);

/* path_cmds */
int		ft_pipex(t_mini *mini);
int		check_error(int return_value, char *message);
void	free_table(char *str, char **tab);
char	*find_cmd(char *cmd, t_env *env);
char	*env_path(t_env *env);
int		execute(char *path, char **args, t_env *env);
int		cmd_path(char **command, t_mini *mini, t_env *env);

#endif
