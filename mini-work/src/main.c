/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2024/03/04 09:20:24 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool ft_isspace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (true);
	return (false);
}

static int	take_input(char *str, t_mini *mini)
{
	char	*buf;
	t_env	*env;
	char	cwd[1024];
	int		i;
	
	i = 0;
	env = mini->env;
	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " % ", 1024);
	buf = readline(cwd);
	if (buf == NULL)
	{
		ctrl_d(0);
		return (0);
	}
	while (buf[i] && (ft_isspace(buf[i]) == true))
	{
	 	if (buf[i + 1] == '\0')
	 	{
		 	ft_strlcat(cwd, " % ", 1024);
	 	 	return (0);
		}
		i++;
 	}
	if (ft_strlen(buf) != 0)
	{
		add_history(buf);
		ft_strcpy(str, buf);
		//tokenize the str into tken (tableaux pour envoyer aux commandes), split seulement pour tester cmds
		parse(str, env, mini);
		return (0);
	}
	return (1);
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
	char	inputstr[1024];
	t_mini	mini;
	t_env	*env;

	(void)argv;
	(void)argc;
	env = init_env(&mini, envp);
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (take_input(inputstr, &mini))
			continue ;
	}
	return (0);
}
