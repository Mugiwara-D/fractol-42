/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:43:18 by maderuel          #+#    #+#             */
/*   Updated: 2022/11/28 12:43:26 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*blc;

	if (!lst || !*lst || !del)
		return ;
	blc = *lst;
	while (blc)
	{	
		tmp = blc->next;
		del(blc->content);
		free(blc);
		blc = tmp;
	}
	*lst = NULL;
}
