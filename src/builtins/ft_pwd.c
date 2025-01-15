
#include "../../include/minishell.h"
#include <limits.h>
#include <unistd.h>

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

int main()
{
	return (ft_pwd());
}
