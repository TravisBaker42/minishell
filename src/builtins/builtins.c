




///@Brief:	Checks if its a builtin. Returns 1 if yes, 0 if else.
///@To_do:
///@Notes:	Whoever calls this function should supply the first argument from
///			the array, ie. arg[0];
///			This function should be called before execution for builtins.
int	is_it_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		return (1);
	return (0);
}

///@Brief:	Executes the cmd based on the first arg in the array.
///@To_do:	Include t_env or the struct above that after ft_unset is implemneted?
///			Implement ft_unset;
///@Notes;	Assuming it's grabbed from t_cmd_list
int exec_builtins(char **args, t_data *data)
{
	int	ret_code;

	if (ft_strncmp(cmd, "echo", 4) == 0)
		ret_code = ft_echo(arg);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		ret_code = ft_cd(arg);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		ret_code = ft_pwd(void);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		//ret_code = ft_export();
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		//ret_code = ft_unset();
	else if (ft_strncmp(cmd, "env", 3) == 0)
		//ret_code = ft_env(data->env);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		//ret_code = ft_exit();
	return (ret_code);
}
