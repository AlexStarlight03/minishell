
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

#include "../include/minishell.h"


void print_prompt()
{
    char cwd[1024];
	getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
}

int	take_input(char* str, t_data data)
{
    char* buf;
  
    buf = readline(" % ");
    if (ft_strlen(buf) != 0) 
	{
        add_history(buf);
        ft_strcpy(str, buf);
		if (strncmp(buf, "env", 3) == 0)
			ft_env(&data);
        return (0);
    } 
	else 
        return (1);
}

char	**ft_init_env(char **envp)
{
	int	i;
	char **ret;

	i = 0;
	while(envp[i])
		i++;
	ret = ft_calloc(sizeof(char *), i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		ret[i] = ft_strdup(envp[i]);
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	char inputstr[1024];
	t_data data;

	data.env = ft_init_env(envp);
	while (1)
	{
		print_prompt();
		if (take_input(inputstr, data))
			continue;
		printf("Here is what you wrote: %s\n", inputstr);
	}
	return (0);
}