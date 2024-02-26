/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:36 by adube             #+#    #+#             */
/*   Updated: 2024/02/25 22:08:37 by mchampag         ###   ########.fr       */
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
# include <errno.h>

// # include <termios.h>

# define CD 10
# define ECHO 11
# define ENV 12
# define EXIT 13
# define EXPORT 14
# define PWD 15
# define UNSET 16

# define NON  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

int		ERROR;

typedef enum e_toktype
{
	TOK_ERROR,
	TOK_WORD,
	TOK_SPACE,
	TOK_DIGIT,
	TOK_OPERATOR,
	TOK_REDIRECTION,
}	t_toktype;

typedef struct s_tokens
{
	t_toktype	token;
	char		*data;
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

/* BUILTINS */
int		cd(t_env *env, char **args);
void	ft_echo(char **args);
int		ft_env(t_env *env);
void	ft_exit(t_mini *mini, t_env *env);
int		ft_export(char **cmd, t_env *env);
int		ft_pwd(void);
bool	ft_unset(t_mini *mini, char **cmd);
/* utils_1 */
void	free_lst_node(t_mini *mini, t_env *env);
t_env	*lstsecondlast(t_env *lst);
char	*get_var_name(char *dest, char *src);
/* utils_2 */ 
char	*env_str(t_env *list);
int		check_env(t_env *env, char *args);
bool	env_add_back(t_env *env, char *str);

/* PARSING */
int		is_a_builtin(char **args);
void	parser(char *input, t_env *env, t_mini *mini);
void	exec_builtin(t_mini *mini, t_env *env, char **args, int cmd);
char	*quote_checker(char quote_type, char *arg);
/* path_cmds */
char	*find_cmd(char *cmd, t_env *env);
char	*env_path(t_env *env);
int		cmd_path(char **command, t_mini *mini, t_env *env);

/* PIPEX */
int		ft_pipex(t_mini *mini);
int		check_error(int return_value, char *message);
void	free_table(char *str, char **tab);

/* UTILS */
void    ctrl_c(int signal);
void	ctrl_d(int signal);
void	signals_activation(void);
void    header(void);

/* MAIN */
int		main(int argc, char **argv, char **envp);

#endif
