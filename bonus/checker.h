/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:44 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 20:14:28 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list	t_list;

struct s_list
{
	int				data;
	t_list			*next;
};

int				ft_doubles(int nb, t_list **stack_a);
void			ft_init_stack(t_list **stack_a, char **argv);
void			ft_free_arr(char **tab);
int				ft_isnumber(char *str);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
long			ft_atoi(const char *str);
int				ft_isspace(char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(int data);
void			ft_lstclear(t_list **lst);
int				is_sorted(t_list **stack_a);
int				sa(t_list **a);
int				sb(t_list **b);
int				ss(t_list **a, t_list **b);
int				ra(t_list **a);
int				rb(t_list **b);
int				rr(t_list **a, t_list **b);
int				rra(t_list **a);
int				rrb(t_list **b);
int				rrr(t_list **a, t_list **b);
int				pa(t_list **a, t_list **b);
int				pb(t_list **a, t_list **b);

int				create_node(t_list **inst, int nb);
void			_ft_exit(t_list **a, t_list **b, t_list **inst, char *line);
void			ft_exit(t_list **a, t_list **inst, char **args);
void			free_stacks(t_list **a, t_list **b, t_list **inst);
void			apply_insttructions(t_list **a, t_list **b, t_list **inst);
int				is_sorted(t_list **stack_a);
void			checker_3(t_list **a, t_list **b, t_list **inst, char *line);
void			checker_2(t_list **a, t_list **b, t_list **inst, char *line);
void			checker_1(t_list **a, t_list **b, t_list **inst, char *line);
void			checker(t_list **a, t_list **b);

#endif