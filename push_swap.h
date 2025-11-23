/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:09 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/22 17:09:53 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>


typedef struct s_lst
{
	long long		data;
	struct s_lst	*next;
}	t_lst;

int	error_msg(char *msg);
int	validate(char **argv, t_lst *data);

#endif