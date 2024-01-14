/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:14:23 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 17:29:41 by tamehri          ###   ########.fr       */
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

t_inst	*ft_instnew(char *inst)
{
	t_inst	*head;

	head = (t_inst *)malloc(sizeof(t_inst));
	if (!head)
		return (NULL);
	head->inst = inst;
	head->next = NULL;
	return (head);
}

void	ft_instadd_back(t_inst **lst, t_inst *new)
{
	t_inst	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	create_node(t_inst **inst, char *s)
{
	t_inst	*new;

	new = ft_instnew(s);
	if (!new)
		return (0);
	ft_instadd_back(inst, new);
	return (1);
}

void	ft_instclear(t_inst **inst)
{
	t_inst	*temp;

	if (!*inst)
		return ;
	temp = *inst;
	while (inst && *inst)
	{
		temp = temp->next;
		free(*inst);
		*inst = temp;
	}
	*inst = NULL;
}

void	checker_next(t_list **a, t_list **b, t_inst **inst, char *line)
{
		(void)a;
	(void)b;
	if (!ft_strcmp(line, "ra\n"))
		create_node(inst, "ra\n");
	else if (!ft_strcmp(line, "rb\n"))
		create_node(inst, "rb\n");
	else if (!ft_strcmp(line, "rr\n"))
		create_node(inst, "rr\n");
	else if (!ft_strcmp(line, "rra\n"))
		create_node(inst, "rra\n");
	else if (!ft_strcmp(line, "rrb\n"))
		create_node(inst, "rrb\n");
	else if (!ft_strcmp(line, "rrr\n"))
		create_node(inst, "rrr\n");
	else if (!ft_strcmp(line, "pb\n"))
		create_node(inst, "pb\n");
	// else
		// ft_exit(a, b, inst, NULL, line);
}
#include <stdio.h>

void	checker(t_list **a, t_list **b)
{
	char	*line;
	t_inst	*inst;

	(void)a;
	(void)b;
	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		int d = create_node(&inst, line);
		printf("%d\n%s\n", d, inst->inst);
		break ;
		// if (!ft_strcmp(line, "sa\n"))
		// 	create_node(&inst, "sa\n");
		// else if (!ft_strcmp(line, "sb\n"))
		// 	create_node(&inst, "sb\n");
		// else if (!ft_strcmp(line, "ss\n"))
		// 	create_node(&inst, "ss\n");
		// else if (!ft_strcmp(line, "pa\n"))
		// 	create_node(&inst, "pa\n");
		// else if (!ft_strcmp(line, ""))
		// 	break ;
		// else
		// 	checker_next(a, b, &inst, line);
		// free(line);
		// line = NULL;
	}
	// apply_insttructions(a, b, &inst);
	// if (is_sorted(a) && !(*b))
	// 	ft_putstr_fd("OK\n", 1);
	// else
	// 	ft_putstr_fd("KO\n", 1);
}
