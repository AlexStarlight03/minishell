/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2024/01/29 14:52:52 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../lib/pipex/pipex.h"


int	take_input(char *str, t_mini *mini)
{
	char	*buf;
	//char	**args;
	t_env	*env;
	char	cwd[1024];
	
	env = mini->env;
	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " % ", 1024);
	buf = readline(cwd);
	if (ft_strlen(buf) != 0) 
	{
		add_history(buf);
		ft_strcpy(str, buf);
		//tokenize the str into tken (tableaux pour envoyer aux commandes), split seulement pour tester cmds
		parse(str, env, mini);
		return (0);
	}
	else
		return (1);
}

t_env	*ft_init_env(t_mini *mini, char **envp)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	if (envp[0] == NULL)
		return (NULL);
	env->content = ft_strdup(envp[0]);
	env->next = NULL;
	mini->env = env;
	i = 1;
	while (envp && envp[i])
	{
		new = malloc(sizeof(t_env));
		if (new == NULL)
			return (NULL);
		new->content = ft_strdup(envp[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	char	inputstr[1024];
	t_mini	mini;
	t_env	*env;

	(void)argv;
	if (argc != 1)
	{
		//error_function;
		exit(127);
	}
	env = ft_init_env(&mini, envp);
	while (1)
	{
		//pipex(argc, argv, envp);
		if (take_input(inputstr, &mini))
			continue ;
	}
	return (0);
}
