/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:09 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/26 19:19:02 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_lst
{
	long long		data;
	int				index;
	struct s_lst	*next;
}	t_lst;

typedef struct s_box
{
	char	**split;
	int		size_a;
	int		size_b;
	t_lst	*a;
	t_lst	*b;
}	t_box;

int		error_msg(char *msg, t_box *box);
int		validate(char **argv, t_lst *data, t_box *box);
void	sa(t_box *box, bool print);
void	sb(t_box *box, bool print);
void	ss(t_box *box);
void	pa(t_box *box, bool print);
void	pb(t_box *box, bool print);
void	rr(t_box *box);
void	rb(t_box *box, bool print);
void	ra(t_box *box, bool print);
void	rra(t_box *box, bool print);
void	rrr(t_box *box, bool print);
void	rrb(t_box *box, bool print);
void	rra(t_box *box, bool print);
void	add_index(t_lst *lst);
void	radix_sort(t_box *box);
int		check(t_box *box);

#endif