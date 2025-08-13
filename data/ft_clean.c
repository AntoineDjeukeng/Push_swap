/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjeuken <adjeuken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 03:02:07 by adjeuken          #+#    #+#             */
/*   Updated: 2025/08/13 09:09:11 by adjeuken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_clean_stac(t_stack *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if ((s->state == 1 && !s->is_sorted))
		ft_dprintf(2, "Error\n");
	if ((s->state == 1 && s->is_sorted == 1 && s->bonus == 1))
		ft_dprintf(1, "OK\n");
	if ((s->state == 0 && s->is_sorted == 0 && s->bonus == 1))
		ft_dprintf(1, "KO\n");
	free_list(s->a);
	free_list(s->b);
	if (s->op_count > 0)
	{
		while (i < s->op_count)
			free(s->ops[i++]);
	}
	if (s->ops)
		free(s->ops);
	if (s->values)
		free(s->values);
	if (s->line)
		free(s->line);
	free(s);
}

int	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_issearch(line[i], " \t\n\v\f\r"))
			return (0);
		i++;
	}
	return (1);
}
