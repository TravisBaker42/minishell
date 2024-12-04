#include "minishell.h"
///	@brief iterates i while input == space or tab and returns i
///	space == 32 and tab == 9
///
///	@prama i: current position in the string
///	@prama input: command line input string
int	ft_iterates_space(const	char *input, int i)
{
	while ((input[i] == 32 || input[i] == 9) &&  input[i] != '\0')
	   i++;	
	return (i);
}
