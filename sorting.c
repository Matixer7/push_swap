/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:04:08 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 20:18:41 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	radix_sort(t_box *box)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_num = box->size_a - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = box->size_a;
		while (++j < size)
		{
			if (((box->a->index >> i) & 1) == 1)
				ra(box, true);
			else
				pb(box, true);
		}
		while (box->size_b > 0)
			pa(box, true);
	}
}
