/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:30:57 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/23 20:18:17 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates_eliminator(long long n, t_lst *data)
{
	t_lst	*checker;

	if (!data)
		return (0);
	checker = data;
	while (checker)
	{
		if (checker->data == n)
			return (error_msg("Data cannot duplicate\n"));
		checker = checker->next;
	}
	return (0);
}

long long	ft_atol(char *s)
{
	int			i;
	long long	n;
	long long	sign;

	i = -1;
	n = 0;
	sign = 1;
	if (!s || !s[0])
		return (error_msg("Found incorrect data!1\n"));
	if (s[0] == '-')
	{
		sign = -sign;
		i++;
	}
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (error_msg("Found incorrect data!1\n"));
		n = n * 10 + (s[i] - 48);
	}
	if ((n * sign) > INT_MAX || (n * sign) < INT_MIN)
		return (error_msg("Found incorrect data!2\n"));
	return (n * sign);
}

int	validate(char **argv, t_lst *data)
{
	int			i;
	long long	n;
	t_lst		*tail;
	t_lst		*new;

	if (!argv || !data || !argv[0])
		return (error_msg("Invalid input to validate\n"));
	n = ft_atol(argv[0]);
	data->data = n;
	data->next = NULL;
	tail = data;
	i = 0;
	while (argv[++i])
	{
		n = ft_atol(argv[i]);
		duplicates_eliminator(n, data);
		new = malloc(sizeof(t_lst));
		if (!new)
			return (error_msg("Malloc failed\n"));
		new->data = n;
		new->next = NULL;
		tail->next = new;
		tail = new;
	}
	return (0);
}
