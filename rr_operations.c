/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:36:23 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 19:41:32 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_box *box, bool print)
{
	t_lst	*last;
	t_lst	*prev;

	if (box->size_a < 2)
		return ;
	last = box->a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = box->a;
	box->a = last;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_box *box, bool print)
{
	t_lst	*last;
	t_lst	*prev;

	if (box->size_b < 2)
		return ;
	last = box->b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = box->b;
	box->b = last;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_box *box, bool print)
{
	rra(box, print);
	rrb(box, print);
	if (print)
		ft_printf("rrr\n");
}
