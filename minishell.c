/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:14:35 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:55:58 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	shell_loop(char **en)
{
	char	*line;
	pid_t	pid;

	while (1)
	{
		line = readline("minishell> ");
		if (!ft_strncmp("exit", line, 5))
			exit(1);
		pid = fork();
		if (!pid)
			exec(line, en);
		wait(NULL);
	}
	free(line);
}

int	main(int ac, char **av, char **en)
{
	if (ac != 1)
	{
		write(STDERR_FILENO, "Usage: ", 7);
		write(STDERR_FILENO, av[0], ft_strlen(av[0], '\n'));
		write(STDERR_FILENO, "\n", 1);
		exit(1);
	}
	shell_loop(en);
}
