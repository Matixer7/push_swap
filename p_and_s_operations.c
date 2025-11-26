/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_and_s_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:10:24 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/26 17:12:18 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_box *box, bool print)
{
	long long	tmp;

	if (box->size_a < 2)
		return ;
	tmp = box->a->next->data;
	box->a->next->data = box->a->data;
	box->a->data = tmp;
	tmp = box->a->next->index;
	box->a->next->index = box->a->index;
	box->a->index = tmp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_box *box, bool print)
{
	long long	tmp;

	if (box->size_b < 2)
		return ;
	tmp = box->b->next->data;
	box->b->next->data = box->b->data;
	box->b->data = tmp;
	tmp = box->b->next->index;
	box->b->next->index = box->b->index;
	box->b->index = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_box *box)
{
	sa(box, false);
	sb(box, false);
	ft_printf("ss\n");
}

void	pa(t_box *box, bool print)
{
	t_lst	*node;

	if (box->size_b < 1)
		return ;
	node = box->b;
	box->b = node->next;
	node->next = box->a;
	box->a = node;
	box->size_a++;
	box->size_b--;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_box *box, bool print)
{
	t_lst	*node;

	if (box->size_a < 1)
		return ;
	node = box->a;
	box->a = node->next;
	node->next = box->b;
	box->b = node;
	box->size_b++;
	box->size_a--;
	if (print)
		ft_printf("pb\n");
}
