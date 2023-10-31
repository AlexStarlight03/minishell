/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:17 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 13:04:16 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_prompt()
{
	char	cwd[1024];
	
	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
}

int	take_input(char* str, t_mini mini)
{
	char*	buf;

	buf = readline(" % ");
	if (ft_strlen(buf) != 0) 
	{
		add_history(buf);
		ft_strcpy(str, buf);
		return (0);
	}
	else
		return (1);
}

int	ft_init_env(t_mini *mini, char **envp)
{
	t_env 	*env;
	t_env 	*new;
	int		i;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (1);
	if (envp[0] == NULL)
		return (1);
	env->content = ft_strdup(envp[0]);
	env->next = NULL;
	mini->env = env;
	i = 1;
	while (envp && envp[i])
	{
		new = malloc(sizeof(t_env));
		if (new == NULL)
			return (1);
			new->content = ft_strdup(envp[i]);
			new->next = NULL;
			env->next = new;
			env = new;
			i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	inputstr[1024];
	t_mini	mini;
	
	ft_init_env(&mini, envp);
	while (1)
	{
		print_prompt();
		if (take_input(inputstr, mini))
			continue;
		printf("Here is what you wrote: %s\n", inputstr);
	}
	return (0);
}
