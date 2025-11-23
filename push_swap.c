/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/22 17:12:30 by mgumienn         ###   ########.fr       */
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
	t_lst	data;

	if (argc < 2)
		return (ft_printf("Not enough arguments given\n"), 0);
	if (argc == 2)
		validate(ft_split(argv[1], ' '), &data);
	if (argc >= 3)
		validate(&argv[1], &data);
}
