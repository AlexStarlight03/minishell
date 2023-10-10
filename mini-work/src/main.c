
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}


int	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);

	while (src[i])
	{
			dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}


void print_prompt()
{
    char cwd[1024];
	getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
}


int	take_input(char* str)
{
    char* buf;
  
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

int	main()
{
	char inputstr[1024];	
	while (1)
	{
		print_prompt();
		if (take_input(inputstr))
			continue;
		printf("Here is what you wrote: %s\n", inputstr);
	}
	return (0);
}