#include "push_swap.h"

static void assign_idx(t_stack *stack)
{
	t_stack *current;
	t_stack *compare;

	current = stack;
	while (current)
	{
		current->index = 0;

		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

static int get_chunk_size(int number)
{
	int root;

	if (number <= 0)
		return (0);

	root = 1;
	while (root <= number / root)
		root++;
	return (root - 1);
}

static int get_max_idx_position(t_stack *stack_b)
{
	int	max_value;
	int	max_idx;
	int current_idx;

	if (!stack_b)
		return (0);

	max_value = stack_b->index;
	max_idx = 0;
	current_idx = 1;
	stack_b = stack_b->next;
	while(stack_b)
	{
		if (stack_b->index > max_value)
		{
			max_value = stack_b->index;
			max_idx = current_idx;
		}
		current_idx++;
		stack_b = stack_b->next;
	}
	return (max_idx);
}

static void push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx, int chunk_size)
{
	int pushed;

	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			pb(stack_a, stack_b, ctx);
			rb(stack_b, ctx, 1);
			pushed++;
		}
		else if ((*stack_a)->index <= pushed + chunk_size)
		{
			pb(stack_a, stack_b, ctx);
			pushed++;
		}
		else
			ra(stack_a, ctx, 1);
	}
}

static void push_chunks_to_a(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int size; 
	int max_idx;

	while (*stack_b)
	{
		size = get_stack_size(*stack_b);
		max_idx = get_max_idx_position(*stack_b);
		while (max_idx != 0)
		{
			if (max_idx <= size / 2)
			{
				rb(stack_b, ctx, 1);
				max_idx--;
			}
			else
			{
				rrb(stack_b, ctx, 1);
				max_idx++;
				if (max_idx == size)
					max_idx = 0; 
			}
		}
		pa(stack_a, stack_b, ctx);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	int	size;
	int	chunk_size;

	assign_idx(*stack_a);
	
	size = get_stack_size(*stack_a);
	chunk_size = get_chunk_size(size);

	push_chunks_to_b(stack_a, stack_b, ctx, chunk_size);
	push_chunks_to_a(stack_a, stack_b, ctx);
}
