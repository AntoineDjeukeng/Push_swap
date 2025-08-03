/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjeuken  <adjeuken@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:29:01 by adjeuken          #+#    #+#             */
/*   Updated: 2025/07/27 14:35:13 by adjeuken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_two(Stack *a)
{
	if (a->top > 0 && a->data[a->top] > a->data[a->top - 1])
		sa(a);
}

void	sort_three(Stack *a, Stack *b)
{
	int	min_idx;
	int	size;
	int	from_top;
	int	rotations;

	min_idx = find_min_index(a);
	size = a->top + 1;
	from_top = a->top - min_idx;
	if (from_top <= size / 2)
	{
		while (from_top-- > 0)
			ra(a);
	}
	else
	{
		rotations = size - from_top;
		while (rotations-- > 0)
			rra(a);
	}
	pb(a, b);
	sort_two(a);
	pa(a, b);
}

void	bring_min_to_top(Stack *a)
{
	int	min_idx;
	int	size;
	int	from_top;
	int	rotations;

	min_idx = find_min_index(a);
	size = a->top + 1;
	from_top = a->top - min_idx;
	if (from_top <= size / 2)
	{
		while (from_top-- > 0)
			ra(a);
	}
	else
	{
		rotations = size - from_top;
		while (rotations-- > 0)
			rra(a);
	}
}

void	sort_n(Stack *a, Stack *b, int n)
{
	if (n <= 1)
		return ;
	if (n == 2)
	{
		sort_two(a);
		return ;
	}
	if (n == 3)
	{
		sort_three(a, b);
		return ;
	}
	bring_min_to_top(a);
	pb(a, b);
	sort_n(a, b, n - 1);
	pa(a, b);
}
