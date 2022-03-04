/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:46:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 06:25:33 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_stacks
{
	int	*a;
	int	*chunks;
	int	*b;
	int	top_a;
	int	bot;
	int	top_b;
	int	n_values;
	int	n_chunks;
	int	chunk_count;
	int	hold_first;
	int	hold_second;
	int	position_n;
	int	position_n_s;
	int	count_moves;
	int	count_2;
	int	rotate;
	int	temp;
	int	temp2;
}	t_stacks;

void	error_input(int argc, char *argv[]);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
void	init_stacks(t_stacks *stack, int argc);
void	fill_stack_a(t_stacks *stack, int argc, char *argv[]);
void	set_chunks(t_stacks *stack);
void	action_sa(t_stacks *stack);
void	action_sb(t_stacks *stack);
void	action_ra(t_stacks *stack);
void	action_rb(t_stacks *stack);
void	action_rra(t_stacks *stack);
void	action_rrb(t_stacks *stack);
void	action_pa(t_stacks *stack);
void	action_pb(t_stacks *stack);
void	sort_small(t_stacks *stack);
void	sort_five(t_stacks *stack);
void	sort_medium(t_stacks *stack);
void	rotate_back(t_stacks *stack);
void	check_next_n(t_stacks *stack);
int		check_who_is_near(t_stacks *stack);
int		check_ascending(t_stacks *stack);
void	move_n_to_top_a(t_stacks *stack, int pos, int n);
void	move_n_to_b(t_stacks *stack, int n);
void	move_all_to_a(t_stacks *stack);
void	rotate_and_decrease(t_stacks *stack);
void	rotate_and_increase(t_stacks *stack);
void	free_stacks(t_stacks *stack);

#endif