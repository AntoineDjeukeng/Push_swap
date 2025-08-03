/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjeuken <adjeuken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:34:57 by adjeuken          #+#    #+#             */
/*   Updated: 2025/08/03 19:08:36 by adjeuken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_node *s)
{
	int		min_idx;
	int		idx;
	int		min_val;
	t_node	*curr;

	min_idx = 0;
	idx = 0;
	curr = s;
	if (!curr)
		return (-1);
	min_val = curr->value;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_idx = idx;
		}
		curr = curr->next;
		idx++;
	}
	return (min_idx);
}

void	sort_two(t_stack *s)
{
	if (s->a && s->a->next && s->a->value > s->a->next->value)
		sa(s);
}

int	get_stack_size(t_node *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	sort_three(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = s->a->value;
	b = s->a->next->value;
	c = s->a->next->next->value;
	if (a > b && b < c && a < c)
		sa(s);
	else if (a > b && b > c)
	{
		sa(s);
		rra(s);
	}
	else if (a > b && b < c && a > c)
		ra(s);
	else if (a < b && b > c && a < c)
	{
		sa(s);
		ra(s);
	}
	else if (a < b && b > c && a > c)
		rra(s);
}

void	sort_n(t_stack *s, int n)
{
	if (n <= 1)
		return ;
	if (n == 2)
	{
		sort_two(s);
		return ;
	}
	if (n == 3)
	{
		sort_three(s);
		return ;
	}
	bring_smallest_to_top(s);
	pb(s);
	sort_n(s, n - 1);
	pa(s);
}
