/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 19:23:07 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(char *msg)
{
	while (*msg)
	{
		write(2, msg, 1);
		msg++;
	}
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_box	box;
	t_lst	a;
	t_lst	b;

	box.a = &a;
	box.b = &b;
	box.size_b = 0;
	if (argc < 2)
		return (ft_printf("Not enough arguments given\n"), 0);
	if (argc == 2)
	{
		validate(ft_split(argv[1], ' '), box.a);
		box.size_a = count_words(argv[1], ' ');
	}
	if (argc >= 3)
	{
		validate(&argv[1], box.a);
		box.size_a = argc - 1;
	}
	rra(&box, true);
}
