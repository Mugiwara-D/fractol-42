/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:17 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/28 12:42:29 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*swp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else if (lst && *lst)
	{
		swp = *lst;
		while (swp->next)
			swp = swp->next;
		swp->next = new;
	}
}
