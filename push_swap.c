/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/26 18:16:16 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_tlst(t_lst **lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_exit(t_box *box)
{
	t_lst	*tmp;
	char	**s;
	int		i;

	if (!box)
		exit(0);
	tmp = box->a;
	if (tmp)
		clear_tlst(&tmp);
	tmp = NULL;
	if (box->size_b != 0)
		tmp = box->b;
	if (tmp)
		clear_tlst(&tmp);
	if (box->split)
	{
		s = box->split;
		i = -1;
		while (s && s[++i])
			free(s[i]);
		free(box->split);
	}
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
	t_lst	b;

	box.a = malloc(sizeof(t_lst));
	box.a->next = NULL;
	box.split = NULL;
	box.b = &b;
	box.size_b = 0;
	if (argc < 2)
		return (error_msg("Not enough arguments given\n", &box), 0);
	if (argc == 2)
	{
		box.split = ft_split(argv[1], ' ');
		box.size_a = validate(box.split, box.a, &box);
	}
	if (argc >= 3)
		box.size_a = validate(&argv[1], box.a, &box);
	add_index(box.a);
	if (!check(&box))
		radix_sort(&box);
	ft_exit(&box);
}
