/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2024/02/08 11:56:59 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


static int	take_input(char *str, t_mini *mini)
{
	char	*buf;
	t_env	*env;
	char	cwd[1024];
	
	env = mini->env;
	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " % ", 1024);
	buf = readline(cwd);
	if (buf)  //ft_strlen(buf) != 0
	{
		add_history(buf);
		ft_strcpy(str, buf);
		//tokenize the str into tken (tableaux pour envoyer aux commandes), split seulement pour tester cmds
		parse(str, env, mini);
		printf("\n %s \n", strerror(errno));
		printf("\n %d \n", errno);
		return (0);
	}
	else
	{
		ctrl_d(0);
		return (1);
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
	// free(new->content);
	// free(new->next->content);
	// free(new);
//	mini->env = env;
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
