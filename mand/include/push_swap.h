/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:47:43 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 15:59:50 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list	t_list;

struct s_list
{
	int				data;
	int				med;
	unsigned int	cheap;
	unsigned int	position;
	t_list			*target;
	t_list			*next;
};

int				ft_isdigit(int c);
long			ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
void			ft_putstr_fd(char *s, int fd);
t_list			*ft_lstnew(int data);
t_list			*ft_lstlast(t_list *lst);
unsigned int	ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);

int				sa(t_list **a);
int				sb(t_list **b);
int				ss(t_list **a, t_list **b);
int				ft_swap(t_list **a);
int				pa(t_list **a, t_list **b);
int				pb(t_list **a, t_list **b);
int				push(t_list **stack_to, t_list **stack_from);
int				ra(t_list **a);
int				rb(t_list **b);
int				rr(t_list **a, t_list **b);
int				rotate(t_list **stack);
int				rra(t_list **a);
int				rrb(t_list **b);
int				rrr(t_list **a, t_list **b);
int				reverse_rotate(t_list **stack);

/* FUNCTIONS */
unsigned int	cost_to_top(t_list **stack, t_list **cur);
unsigned int	max_value(unsigned int x, unsigned int y);
t_list			*find_cheapest(t_list **a);
int				loop_rrr_b(t_list **a, t_list **b, t_list *cheapest);
int				loop_rr_b(t_list **a, t_list **b, t_list *cheapest);
int				loopsingle_b(t_list **a, t_list **b, t_list *cheapest);
int				move_cheapest_b(t_list **a, t_list **b, t_list *cheapest);
int				is_min(int data, t_list **stack);
t_list			*find_max(t_list **stack);
t_list			*find_target_b(int data, t_list **stack);
unsigned int	cheap_set_b(t_list **a, t_list **b, t_list **cur);
void			set_everything_b(t_list **a, t_list **b);
void			sort_to_b(t_list **a, t_list **b);
int				loop_rrr_a(t_list **a, t_list **b, t_list *cheapest);
int				loop_rr_a(t_list **a, t_list **b, t_list *cheapest);
int				loopsingle_a(t_list **a, t_list **b, t_list *cheapest);
int				move_cheapest_a(t_list **a, t_list **b, t_list *cheapest);
int				is_max(int data, t_list **stack);
t_list			*find_min(t_list **stack);
t_list			*find_target_a(int data, t_list **stack);
unsigned int	cheap_set_a(t_list **a, t_list **b, t_list **cur);
void			set_everything_a(t_list **a, t_list **b);
void			sort_to_a(t_list **a, t_list **b);
int				ft_min(t_list **a);
void			ft_sort3(t_list **a);
void			ft_sort4(t_list **stack_a, t_list **stack_b);
void			simple_sort(t_list **stack_a, t_list **stack_b, int size);
int				is_sorted(t_list **stack_a);
void			sort_stack(t_list **stack_a, t_list **stack_b);
void			free_stacks(t_list **a, t_list **b);
void			ft_free_arr(char **tab);
void			ft_exit(t_list **a, t_list **b, char **args);
int				ft_isnumber(char *str);
t_list			*unpenetrable_parcing(char *s);
int				ft_doubles(int nb, t_list **stack_a);
void			ft_set_positions(t_list **a);
void			ft_init_stack(t_list **stack_a, char **argv);

#endif
