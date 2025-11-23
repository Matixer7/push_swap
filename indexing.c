/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:16:35 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 20:19:09 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index_to_list(t_lst *lst, long long *arr, int count)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < count)
		{
			if (lst->data == arr[i])
			{
				lst->index = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

static void	bubble_sort(long long *arr, int count)
{
	int			i;
	int			j;
	long long	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	count_nodes(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static long long	*make_array_from_list(t_lst *lst, int count)
{
	long long	*arr;
	int			i;

	(void)count;
	arr = (long long *)malloc(sizeof(long long) * count);
	if (!arr)
		return (NULL);
	i = 0;
	while (lst)
	{
		arr[i++] = lst->data;
		lst = lst->next;
	}
	return (arr);
}

void	add_index(t_lst *lst)
{
	int			count;
	long long	*arr;
	t_lst		*head;

	if (!lst)
		return ;
	head = lst;
	count = count_nodes(head);
	arr = make_array_from_list(head, count);
	if (!arr)
		return ;
	bubble_sort(arr, count);
	assign_index_to_list(head, arr, count);
	free(arr);
}
