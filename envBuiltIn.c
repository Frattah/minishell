/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envBuiltin.c                                       :+:      :+:    :+:   */
/*           	                                      +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:39:44 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/26 11:40:25 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(char *entry, t_lst l)
{
	char	*s;

	s = ft_substr(entry, 0, first_occ(entry, '='));
	put_lst(l, s, entry + first_occ(entry, '=') + 1);
	free(s);
}
