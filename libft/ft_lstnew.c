/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:52:49 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/02 16:10:58 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lsc;

	lsc = (t_list *)malloc(sizeof(*lsc));
	if (!lsc)
		return (NULL);
	lsc->content = content;
	lsc->next = NULL;
	return (lsc);
}	
