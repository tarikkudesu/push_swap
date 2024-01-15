/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:14:23 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/15 20:11:22 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_list **stack_a)
{
	t_list			*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	checker_3(t_list **a, t_list **b, t_list **inst, char *line)
{
	if (!ft_strcmp(line, "rra\n"))
	{
		if (!create_node(inst, 41))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "rrb\n"))
	{
		if (!create_node(inst, 42))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "rrr\n"))
	{
		if (!create_node(inst, 43))
			_ft_exit(a, b, inst, line);
	}
	else
		_ft_exit(a, b, inst, line);
}

void	checker_2(t_list **a, t_list **b, t_list **inst, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
	{
		if (!create_node(inst, 31))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "rb\n"))
	{
		if (!create_node(inst, 32))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "rr\n"))
	{
		if (!create_node(inst, 33))
			_ft_exit(a, b, inst, line);
	}
	else
		checker_3(a, b, inst, line);
}

void	checker_1(t_list **a, t_list **b, t_list **inst, char *line)
{
	if (!ft_strcmp(line, "sb\n"))
	{
		if (!create_node(inst, 12))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "ss\n"))
	{
		if (!create_node(inst, 13))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "pa\n"))
	{
		if (!create_node(inst, 21))
			_ft_exit(a, b, inst, line);
	}
	else if (!ft_strcmp(line, "pb\n"))
	{
		if (!create_node(inst, 22))
			_ft_exit(a, b, inst, line);
	}
	else
		checker_2(a, b, inst, line);
}

void	checker(t_list **a, t_list **b)
{
	char	*line;
	t_list	*inst;

	inst = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strcmp(line, ""))
		{
			free(line);
			break ;
		}
		else if (!ft_strcmp(line, "sa\n"))
		{
			if (!create_node(&inst, 11))
				_ft_exit(a, b, &inst, line);
		}
		else
			checker_1(a, b, &inst, line);
		free(line);
		line = get_next_line(0);
	}
	apply_insttructions(a, b, &inst);
}
