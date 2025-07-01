/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:35:30 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/09 20:44:47 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_limits(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->is_min = 0;
		tmp->is_max = 0;
		tmp->is_lowcost = 0;
		tmp = tmp->next;
	}
}

static void	mark_min_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min_node;
	t_stack	*max_node;

	tmp = stack;
	min_node = stack;
	max_node = stack;
	if (!stack)
		return ;
	while (tmp)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	min_node->is_min = 1;
	max_node->is_max = 1;
}

void	mark_limits(t_stack *stack)
{
	if (!stack)
		return ;
	clear_limits(stack);
	mark_min_max(stack);
}

void	mark_lowcost(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*marked;
	int		choosen;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	marked = tmp;
	choosen = abs_v(tmp->cost_to_swap);
	while (tmp)
	{
		if (abs_v(tmp->cost_to_swap) < choosen)
		{
			marked = tmp;
			choosen = abs_v(tmp->cost_to_swap);
		}
		tmp = tmp->next;
	}
	if (marked)
		marked->is_lowcost = 1;
}
