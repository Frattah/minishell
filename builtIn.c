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

void	cd(char *path, t_lst l)
{
	if (path == NULL || !ft_strncmp(path, "~", 2))
	{
		chdir(find_env_var(l, "HOME"));
		return ;
	}
	if (!ft_strncmp(path, "-", 2))
	{
		chdir(find_env_var(l, "OLDPWD"));
		return ;
	}
	chdir(path);
}

void	pwd(t_lst l)
{
	printf("%s\n", find_env_var(l, "PWD"));
}

void	env(t_lst en)
{
	en = en->next;
	while (en != NULL)
	{
		printf("%s=%s\n", en->key, en->val);
		en = en->next;
	}
}

void	echo(char **args)
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
				printf("%s", getenv(delimit_env(str)));
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

void	unset(char *key, t_lst en)
{
	remove_lst(en, key);
}
