/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:34:18 by aseisenb          #+#    #+#             */
/*   Updated: 2022/10/21 15:34:23 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

# define LAST_CHUNCK	10

typedef struct s_stack
{
	t_dlist		*a;
	t_dlist		*b;
	t_list		*instr;
}				t_stack;

typedef struct s_stack_store_a
{
	int			mid_index;
	int			highest_index;
	int			next_index_to_sort;
}				t_stack_store_a;

typedef struct s_stack_store_b
{
	int			mid_index;
	int			highest_index;
	int			lowest_index;
}				t_stack_store_b;

typedef struct s_store
{
	int				*ordered_array;
	int				total_num;
	t_stack_store_a	a;
	t_stack_store_b	b;
}				t_store;

//system
void	return_error(void);
void	clear(t_stack *stack, t_store *store);
void	initialize(t_stack *stack, t_store *store, int argc, char **argv);
void	init_stack_a(int argc, char **argv, t_dlist	**stack_a);
//operations
void	swap(t_dlist **stack, t_list **instr, char id);
void	rotate(t_dlist **stack, t_list **instr, char id);
void	reverse_rotate(t_dlist **stack, t_list **instr, char id);
void	push(t_dlist **origin, t_dlist **dest, t_list **instr, char id);
//sorting
void	sort(t_stack *stack, t_store *store);
void	small_sort(t_stack *stack, t_store *store, int total_numbers);
int		any_small_in_stack_a(t_dlist *stack_a, t_store *store);
void	send_half_to_b(t_stack *stack, t_store *store);
void	return_half_to_a(t_stack *stack, t_store *store, int limit);
void	sort_big_b(t_stack *stack, t_store *store);
void	sort_small_b(t_stack *stack, t_store *store);
void	order_a(t_stack *stack, t_store *store);
//auxilary data structure
void	quick_sort(int *array, int left, int right);
int		find_mid_index(int bigger_index, int smallest_index);
int		reverse_rotation_is_quicker(t_dlist *stack, int target_number);
int		rr_is_quick_mult(t_dlist *stack, int first_num, t_store *store);
void	rewind(t_dlist **stack_to_rewind);
void	fast_forward(t_dlist **stack_to_fast_forward);
void	reduce_operations(t_list **operations);
int		is_full(t_dlist *stack, int total_numbers);
int		is_sorted(t_dlist *stack);
int		last_num_index(t_dlist *stack);
//stack_helpers
int		is_duplicate(t_dlist *lst, int number);
int		*fill_and_sort_array(t_dlist *stack_a, int total);
int		find_true_index(t_stack *stack, t_store *store, int index);
void	assign_indixes_to_stack(t_stack *stack, t_store *store);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
//parsing
void	check_if_arg_are_integer(char **argv, int i);
char	**check_string(int *argc, char **argv);
void	check_args(int argc, char **argv);

#endif
