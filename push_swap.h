/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:35:53 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/25 04:48:36 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

typedef struct s_node
{
	int				data;
	int				pos;
	struct s_node	*next;
}					t_node;

typedef struct Stack
{
	t_node			*top;
	int				size;
	int				values;
	int				min;
	int				max;
}					t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				sa(t_stack *a, int binde);
void				sb(t_stack *b, int binde);
void				ss(t_stack *a, t_stack *b, int binde);
void				pa(t_stack *source, t_stack *destination, int binde);
void				pb(t_stack *source, t_stack *destination, int binde);
void				ra(t_stack *a, int binde);
void				rb(t_stack *b, int binde);
void				rr(t_stack *a, t_stack *b, int binde);
void				rra(t_stack *a, int binde);
void				rrb(t_stack *b, int binde);
void				rrr(t_stack *a, t_stack *b, int binde);

void				push(t_stack *stack, int data);
void				sort_4(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_big_stack(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				sort_stack(t_stack *a, t_stack *b);
void				help_sort(t_stack *a, t_stack *b);
void				push_chunk_a_to_b(t_stack *a, t_stack *b);
void				push_chunk_b_to_a(t_stack *a, t_stack *b);
void				push_b_chunk(t_stack *a, t_stack *b, int end_chunk,
						int mid_chunk);

void				sort_stack_superieur(t_stack *a, t_stack *b,
						int chunk_size);
void				sort_stack_inferieur(t_stack *a, t_stack *b,
						int chunk_size);
void				init_position(t_stack *a);
void				instructions_checker(const char *str, t_stack *a,
						t_stack *b);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				checker(t_stack *a, t_stack *b);
void				ft_error(t_stack *stack);
void				ft_free(t_stack *stack);
void				iter_chunk_inf(t_stack *a, int start_chunk, int chunk_size,
						int end_chunk);
void				iter_chunk_sup(t_stack *a, int start_chunk, int chunk_size,
						int end_chunk);
int					pop(t_stack *stack);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					is_sorted(t_stack *stack);
int					get_min(t_stack *stack);
int					get_max(t_stack *stack);
int					is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
int					get_median(t_stack *a);
int					stack_size(t_stack *stack);
int					get_max_position(t_stack *stack);
int					get_second_max_position(t_stack *stack);
int					ft_strcmp(const char *str1, const char *str2);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlen(const char *str);

t_stack				*parse_args(int argc, char **argv);
t_stack				*initialize_stack(void);

char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *str, int c);
char				*get_next_line(int fd);

#endif