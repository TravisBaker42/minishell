

#include "../../include/minishell.h"
#include <unistd.h>

static int	arg_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int main()
{
	char *arg[] = {"Hello", NULL};

	return (ft_echo(arg));
}
