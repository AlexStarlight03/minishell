/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2024/02/25 23:02:47 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	input_checker(char *buf)
{
	if (!*buf || !buf)
		return (false);
	return(true);	
}

static bool	readline_input(t_mini *mini, char *input)
{
	char	*buf;
	t_env	*env;
	char	cwd[1024];

	env = mini->env;
	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " % ", 1024);
	buf = readline(cwd);
	if (input_checker(buf))  // double prompt affiche si ' '
	{
		add_history(buf);
		ft_strcpy(input, buf);
		parser(input, env, mini);
		return (true);
	}
	buf = NULL;
	return (false);
}

static void	minishell_prompt(t_mini mini, char *input)
{
	while (1)
	{
		if (readline_input(&mini, input))
			continue ;
		else
			ctrl_c(100);
	}
}

static t_env	*init_env(t_mini *mini, char **envp)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = malloc(sizeof(t_env));
	if (env == NULL || envp[0] == NULL)
		return (NULL);
	env->content = ft_strdup(envp[0]);
	env->next = NULL;
	mini->env = env;
	i = 0;
	while (envp && envp[++i])
	{
		new = malloc(sizeof(t_env));
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
	header();
	env = init_env(&mini, envp);
	minishell_prompt(mini, input);
	return (0);
}
