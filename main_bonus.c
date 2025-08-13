/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjeuken <adjeuken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 07:38:34 by adjeuken          #+#    #+#             */
/*   Updated: 2025/08/13 09:16:35 by adjeuken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*s;

	if (argc > 1)
		s = ft_init_stack_list(argc, argv, 1);
	else
		s = NULL;
	if (s && (!s->state || (s->state && s->is_sorted)))
	{
		s->line = get_next_line(0);
		if (!s->line && !s->is_sorted)
			s->state = 1;
		while (s->line)
		{
			if (!ft_empty_line(s->line))
				s->ops[s->op_count++] = ft_strdup(s->line);
			free(s->line);
			s->line = get_next_line(0);
		}
	}
	if (s)
		ft_check_results(s);
	ft_clean_stac(s);
	return (0);
}
