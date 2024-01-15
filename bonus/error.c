/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:13:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/15 20:12:36 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_list **a, t_list **b, t_list **inst)
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
	if (inst)
	{
		ft_lstclear(inst);
		*inst = NULL;
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

void	_ft_exit(t_list **a, t_list **b, t_list **inst, char *line)
{
	if (line)
		free(line);
	free_stacks(a, b, inst);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_exit(t_list **a, t_list **inst, char **args)
{
	if (args)
		ft_free_arr(args);
	free_stacks(a, NULL, inst);
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
