/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:30:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/24 18:35:38 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_size(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	duplicates_eliminator(long long n, t_lst *data, t_box *box)
{
	t_lst	*checker;

	if (!data)
		return (0);
	checker = data;
	while (checker)
	{
		if (checker->data == n)
			return (error_msg("Data cannot duplicate\n", box));
		checker = checker->next;
	}
	return (0);
}

long long	ft_atol(char *s, t_box *box)
{
	int			i;
	long long	n;
	long long	sign;

	i = -1;
	n = 0;
	sign = 1;
	if (!s || !s[0])
		return (error_msg("Found incorrect data!1\n", box));
	if (s[0] == '-')
	{
		sign = -sign;
		i++;
	}
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (error_msg("Found incorrect data!1\n", box));
		n = n * 10 + (s[i] - 48);
	}
	if ((n * sign) > INT_MAX || (n * sign) < INT_MIN)
		return (error_msg("Found incorrect data!2\n", box));
	return (n * sign);
}

int	validate(char **argv, t_lst *data, t_box *box)
{
	int			i;
	long long	n;
	t_lst		*tail;
	t_lst		*new;

	if (!argv || !data || !argv[0])
		return (error_msg("Invalid input to validate\n", box));
	n = ft_atol(argv[0], box);
	data->data = n;
	data->next = NULL;
	tail = data;
	i = 0;
	while (argv[++i])
	{
		n = ft_atol(argv[i], box);
		duplicates_eliminator(n, data, box);
		new = malloc(sizeof(t_lst));
		if (!new)
			return (error_msg("Malloc failed\n", box));
		new->data = n;
		new->next = NULL;
		tail->next = new;
		tail = new;
	}
	return (count_size(argv));
}
