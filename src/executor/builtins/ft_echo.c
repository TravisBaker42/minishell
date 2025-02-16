

#include "../../include/minishell.h"
#include <unistd.h>

///@Brief: Counts Number of arguments in the string array.
static int	arg_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

///@Brief: Echos the str with the flag option -n that disables newline.
///@To_do: Double check it behaves the same way as BASH.
>>>>>>> jeschill/builtins
int	ft_echo(char **str)
{
	int	i;
	int	n_options;

	i = 0;
	n_options = 0;
	if (arg_count(str) >= 1)
	{
		while (str[i] && ft_strncmp(str[i], "-n", 2) == 0)
		{
			n_options = 1;
			i++;
		}
		while (str[i])
		{
			ft_putstr_fd(str[i], 1);
			if (str[i + 1] && str[i][1] != '\0')
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (n_options == 0)
		ft_putchar_fd('\n', 1);
	return (SUCCESS);
}

/*
int main()
{	
	char *arg[] = {"", NULL};
	char *arg[] = {NULL};
	char *arg[] = {"Hello", NULL};
	char *arg[] = {"Hello World", NULL};
	char *arg[] = {"Hello", "World", NULL};

	char *arg[] = {"-n", "", NULL};
	char *arg[] = {"-n", NULL};
	char *arg[] = {"-n", "Hello", NULL};
	char *arg[] = {"-n", "Hello World", NULL};
	char *arg[] = {"-n", "Hello", "World", NULL};
	return (ft_echo(arg));
}
*/
