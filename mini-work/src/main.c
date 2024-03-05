/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2024/03/04 21:54:19 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	code;

// static bool	input_checker(char *buf)
// {
// 	if ((ft_strlen(buf) == 1 && buf[0] == 32) || !*buf || !buf) // double prompt si ' ', segfault si plusieurs
// 		return (false);
// 	return(true);	
// }

static bool	readline_input(t_mini *mini, char *input)
{
	char	*buf;
	t_env	*env;
	char	cwd[1024];

	env = mini->env;
	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " % ", 1024);
	buf = readline(cwd);
	if (buf)  // segfault si ' '
	{
		add_history(buf);
		ft_strcpy(input, buf);
		tokenizer(input);
		// parser(input, env, mini); // if
		return (true);
	}
	return (false);
}

static void	minishell_prompt(t_mini mini, char *input)
{
	while (1)
	{
		if (readline_input(&mini, input))
			continue ;
		else
			ctrl_d(code);
	}
}

static t_env	*init_env(t_mini *mini, char **envp)
{
	t_env	*env;
	t_env	*new;
	int		i;

	code = 100;
	env = ft_calloc(1, sizeof(t_env));
	if (env == NULL || envp[0] == NULL)
		return (NULL);
	env->content = ft_strdup(envp[0]);
	env->next = NULL;
	mini->env = env;
	i = 0;
	while (envp && envp[++i])
	{
		new = ft_calloc(1, sizeof(t_env));
		if (new == NULL)
			return (NULL);
		new->content = ft_strdup(envp[i]);
		new->next = NULL;
		env->next = new;
		env = new;
	}
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_mini	mini;
	char	input[1024];
	
	(void)argv;
	(void)argc;
	signals_activation();
	env = init_env(&mini, envp);
	header();
	minishell_prompt(mini, input);
	return (0);
}
