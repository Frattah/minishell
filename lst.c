/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_entry	*init_entry(char *key, char *val)
{
	t_entry	*nw;

	nw = (t_entry *) malloc(sizeof(t_entry));
	if (!nw)
		return (NULL);
	nw->key = (char *) malloc(sizeof(char) * ft_strlen(key, '\0') + 1);
	ft_strlcpy(nw->key, key, ft_strlen(key, '\0') + 1);
	nw->val = (char *) malloc(sizeof(char) * ft_strlen(val, '\0') + 1);
	ft_strlcpy(nw->val, val, ft_strlen(val, '\0') + 1);
	nw->next = NULL;
	return (nw);
}

t_entry	*get_lst(t_lst l, char *key)
{
	l = l->next;
	while (l != NULL)
	{
		if (l->key == NULL)
			return (NULL);
		if (!ft_strncmp(l->key, key, ft_strlen(key, '\0') + 1))
			return (l);
		l = l->next;
	}
	return (NULL);
}

void	put_lst(t_lst l, char *key, char *val)
{
	t_entry	*nw;
	t_entry	*pre;

	pre = l;
	l = l->next;
	nw = init_entry(key, val);
	while (l != NULL)
	{
		if (!ft_strncmp(l->key, key, ft_strlen(key, '\0') + 1))
		{
			nw->next = l->next;
			free(l->key);
			free(l->val);
			free(l);
			break ;
		}
		pre = l;
		l = l->next;
	}
	pre->next = nw;
}

void	remove_lst(t_lst l, char *key)
{
	t_entry	*i;
	t_entry	*j;

	j = l;
	i = l->next;
	while (i != NULL)
	{
		if (!ft_strncmp(i->key, key, ft_strlen(key, '\0') + 1))
		{
			j->next = i->next;
			free(i);
			return ;
		}
		j = i;
		i = i->next;
	}
	return ;
}

char	**convert_lst(t_lst l)
{
	t_entry	*i;
	int		j;
	int		size;
	char	**out;

	i = l;
	size = 0;
	j = 0;
	while (i != NULL)
	{
		size++;
		i = i->next;
	}
	i = l;
	out = (char **) malloc(sizeof(char *) * (size + 1));
	out[size] = NULL;
	while (i != NULL)
	{
		out[j] = (char *) malloc(sizeof(char) * (ft_strlen(i->val, '\0') + 1));
		ft_strlcpy(out[j], i->val, ft_strlen(i->val, '\0') + 1);
		j++;
		i = i->next;
	}
	return (out);
}
