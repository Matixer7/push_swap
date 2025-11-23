/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:34:06 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 19:41:31 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_box *box, bool print)
{
	t_lst	*first;
	t_lst	*last;

	if (box->size_a < 2)
		return ;
	first = box->a;
	box->a = first->next;
	first->next = NULL;
	last = box->a;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_box *box, bool print)
{
	t_lst	*first;
	t_lst	*last;

	if (box->size_b < 2)
		return ;
	first = box->b;
	box->b = first->next;
	first->next = NULL;
	last = box->b;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_box *box)
{
	ra(box, false);
	rb(box, false);
	ft_printf("rr\n");
}
