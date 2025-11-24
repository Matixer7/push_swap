/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/24 18:36:04 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_tlst(t_lst **lst)
{
	t_lst	*cur;
	t_lst	*next;

	if (!lst || !*lst)
		return ;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*lst = NULL;
}

int	ft_exit(t_box *box)
{
	t_lst	*tmp;

	if (!box)
		exit(0);
	tmp = box->a->next;
	if (tmp)
		clear_tlst(&tmp);
	tmp = NULL;
	if (box->size_b != 0)
		tmp = box->b->next;
	if (tmp)
		clear_tlst(&tmp);
	exit(0);
}

int	error_msg(char *msg, t_box *box)
{
	while (*msg)
	{
		write(2, msg, 1);
		msg++;
	}
	ft_exit(box);
	return (0);
}

int	main(int argc, char **argv)
{
	t_box	box;
	t_lst	a;
	t_lst	b;
	char	**split_result;

	box.a = &a;
	box.b = &b;
	box.size_b = 0;
	if (argc < 2)
		return (ft_printf("Not enough arguments given\n"), 0);
	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		box.size_a = validate(split_result, box.a, &box);
		free(split_result);
	}
	if (argc >= 3)
		box.size_a = validate(&argv[1], box.a, &box);
	add_index(box.a);
	radix_sort(&box);
	ft_exit(&box);
}
