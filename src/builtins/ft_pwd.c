
#include "../../include/minishell.h"
#include <limits.h>
#include <unistd.h>


///@Brief: Print the current working directory and siplays to stdout 1.
int	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return (1);
	}
	else
		return (0);
}
/*
int main()
{
	return (ft_pwd());
}
*/
