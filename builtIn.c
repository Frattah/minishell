/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*           	                                      +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char *path, char **en)
{
	if (path == NULL || !ft_strncmp(path, "~", 2))
	{
		chdir(find_env_var(en, "HOME"));
		return ;
	}
	if (!ft_strncmp(path, "-", 2))
	{
		chdir(find_env_var(en, "OLDPWD"));
		return ;
	}
	chdir(path);
}

void	pwd(char **en)
{
	printf("%s\n", find_env_var(en, "PWD"));
}

void	env(char **en)
{
	while (*en)
	{
		printf("%s\n", *en);
		en++;
	}
}

void	echo(char **args, char **en)
{
	char	*str;
	int		nwln;

	nwln = 1;
	if (!ft_strncmp(*args, "-n", 3))
	{
		nwln = 0;
		args++;
	}
	while (*args)
	{
		str = *args;
		while (*str)
		{
			if (*str == '$')
				printf("%s", find_env_var(en, delimit_env(str)));
			write(1, str, 1);
			str++;
		}
		args++;
		if (*args != NULL)
			write(1, " ", 1);
	}
	if (nwln)
		write(1, "\n", 1);
}
