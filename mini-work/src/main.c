/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2023/11/20 11:20:05 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//changer le prompt pour celui de notre choix!
void	print_prompt(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
}

int	take_input(char *str, t_mini *mini)
{
	char	*buf;
	char	**args;
	t_env	*env;

	env = mini->env;
	buf = readline(" % ");
	if (ft_strlen(buf) != 0) 
	{
		add_history(buf);
		ft_strcpy(str, buf);
		//tokenize the str into tken (tableaux pour envoyer aux commandes), split seulement pour tester cmds
		ft_parse(str, env, mini);
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
		print_prompt();
		if (take_input(inputstr, &mini))
			continue ;
		//printf("Here is what you wrote: %s\n", inputstr);
	}
	return (0);
}
