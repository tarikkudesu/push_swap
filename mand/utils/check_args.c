/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:09:29 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 12:32:23 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_list **a, t_list **b)
{
	if (a)
	{
		ft_lstclear(a);
		*a = NULL;
	}
	if (b)
	{
		ft_lstclear(b);
		*b = NULL;
	}
}

void	ft_free_arr(char **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
		free(*(tab + i++));
	free(tab);
}

void	ft_exit(t_list **a, t_list **b, char **args)
{
	if (args)
		ft_free_arr(args);
	free_stacks(a, b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_isnumber(char *str)
{
	int		i;
	char	*tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = str;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	while (*(tmp + i) == '0')
		tmp++;
	while (*(tmp + i))
		i++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	if (i > 10)
		return (0);
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
