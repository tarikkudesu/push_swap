/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:33:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 17:25:21 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void print_list(t_inst **n)
{
    if (n || *n)
        return ;
    t_inst *node = *n;
    while (node != NULL)
	{
        printf("\t%s\n", node->inst);
        node = node->next;
    }
    printf("\n");
}

void	apply_insttructions(t_list **a, t_list **b, t_inst **inst)
{
    printf("----\n");
	print_list(inst);
	(void)a;
	(void)b;
}