// t_list	*ft_lstfirst(t_list *list)
// {
// 	t_list *first;
	
// 	first = list;
// 	return (first);
// }

// void	ft_print_error(int idx_error, char *av)
// {
// 	if (idx_error == 0)
// 	{
// 		printf("%s : %s: No such file or directory\n", av[1], av[2]);
// 		exit(1);
// 	}
// }

// void	ft_condition_error(int ac, char **av)
// {
// 	if (ft_strcmp("env", av[1]) == 0 && ac != 2)
// 		ft_print_error(0, av);
// }

	// ft_condition_error(1, input);
	// if (ft_strcmp("echo", input) == 0)
	// {
	// 	if (ft_strcmp("-n", input) == 0)
	// 		ft_echo_n(input);
	// 	else
	// 		ft_echo(input);
	// }
	// if (ft_strcmp("env", input) == 0)
	// 	ft_env(list);
	// if (ft_strcmp("pwd", input) == 0)
	// 	ft_pwd(env);


// void	ft_env(t_list *list)
// {
// 	ft_printexp(list);
// }

// void	ft_pwd(char **env)
// {
	
// 	while (*env)
// 	{
// 		if (ft_strncmp("PWD", *env, 3) == 0)
// 			printf("%s\n", *env + 4);
// 		env++;
// 	}
// }

// void 	ft_echo_n(char *av)
// {
// 	int	i;
// 	char *str;

// 	i = 3;
// 	while (av[i])
// 	{
// 		str = ft_strjoin(str, av);
// 		if (av[i + 1])
// 		str = ft_strjoin(str, " ");
// 		str++;
// 		i++;
// 	}
// 	printf("%s", str);
// }


// void 	ft_echo(char *av)
// {
// 	int	i;
// 	int j;

// 	i = 2;
// 	j = 0;
// 	while (av[i])
// 	{
// 		j = 0;
// 		while (av[i][j])
// 		{
// 			if (av[i][j] == '\n')
// 				printf("\n");
// 			j++;
// 		}
// 		printf("%s", av[i]);
// 		if (av[i + 1] == NULL)
// 			break;
// 		printf(" ");
// 		i++;
// 	}
	// printf("%s", str);
// }
