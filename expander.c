/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_var(t_lst l, char *key)
{
	size_t	ln;

	ln = ft_strlen(key, '\0') + 1;
	if (key == NULL)
		return (NULL);
	l = l->next;
	while (l != NULL)
	{
		if (!ft_strncmp(l->key, key, ln))
			return (l->val);
		l = l->next;
	}
	return (NULL);
}

void	expand(char **args, t_lst l)
{
	char	*tmp;

	while (*args)
	{
		if ((*args)[0] == '$')
		{
			tmp = find_env_var(l, (*args) + 1);
			if (tmp != NULL)
			{
				free(*args);
				*args = malloc(sizeof(char)
						* ft_strlen(tmp, '\0'));
				ft_strlcpy(*args, tmp, ft_strlen(tmp, '\0')
					+ 1);
			}
		}
		args++;
	}
}

char	*delimit_env(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !(is_space(s[i]) || s[i] == ' '))
		i++;
	return (s + i);
}
