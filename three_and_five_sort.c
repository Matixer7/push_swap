/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_and_five_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:57:25 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/26 18:58:44 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_lst *lst, int index)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->index == index)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

int	sorted(t_lst *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (i != a->index)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

void	sort_three(t_box *box)
{
	int	first;
	int	second;
	int	third;

	first = box->a->index;
	second = box->a->next->index;
	third = box->a->next->next->index;
	if (first > second && second < third && first < third)
		sa(box, true);
	else if (first > second && second > third)
	{
		sa(box, true);
		rra(box, true);
	}
	else if (first > second && second < third && first > third)
		ra(box, true);
	else if (first < second && second > third && first < third)
	{
		sa(box, true);
		ra(box, true);
	}
	else if (first < second && second > third && first > third)
		rra(box, true);
}

void	sort_five(t_box *box)
{
	int		size;
	int		i;
	int		index;
	t_lst	*a;

	i = -1;
	a = box->a;
	index = 0;
	size = box->size_a;
	while (++i < size - 3)
	{
		while (a->index != index)
		{
			if (get_pos(box->a, index) <= size / 2)
				ra(box, true);
			else
				rra(box, true);
			a = box->a;
		}
		pb(box, true);
		index++;
	}
	sort_three(box);
	while (box->size_b > 0)
		pa(box, true);
}

int	check(t_box *box)
{
	if (sorted(box->a))
		return (1);
	if (box->size_a == 2)
		sa(box, true);
	if (box->size_a == 3)
		sort_three(box);
	if (box->size_a == 5)
		sort_five(box);
	return (sorted(box->a));
}
