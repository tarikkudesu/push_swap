/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:13 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 17:29:00 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_doubles(int nb, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (nb == tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*unpenetrable_parcing(char *s)
{
	long	nb;
	t_list	*new;

	while (*s == ' ')
		s++;
	if (!*s)
		return (NULL);
	if (!ft_isnumber(s))
		return (NULL);
	nb = ft_atoi(s);
	if (nb > INT_MAX || nb < INT_MIN)
		return (NULL);
	new = ft_lstnew(nb);
	if (NULL)
		return (NULL);
	return (new);
}

void	ft_init_stack(t_list **stack_a, char **argv)
{
	int		i;
	int		j;
	char	**args;
	t_list	*new;

	i = -1;
	while (*(argv + ++i))
	{
		j = -1;
		args = ft_split(*(argv + i), ' ');
		if (!args || !*args)
			ft_exit(stack_a, NULL, NULL, args, NULL);
		while (*(args + ++j))
		{
			new = unpenetrable_parcing(*(args + j));
			if (!new || !ft_doubles(new->data, stack_a))
				ft_exit(stack_a, NULL, NULL, args, NULL);
			ft_lstadd_back(stack_a, new);
		}
		ft_free_arr(args);
	}
}
#include <stdio.h>

void print(t_list *node) 
{
    while (node != NULL) 
    {
        printf(" %d \n", node->data);
        node = node->next;
    }
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (1 == argc || (2 == argc && !**(argv + 1)))
		return (1);
	stack_b = NULL;
	stack_a = NULL;
	ft_init_stack(&stack_a, argv + 1);
	checker(&stack_a, &stack_b);
	// print(stack_a);
	free_stacks(&stack_a, &stack_b, NULL);
}
